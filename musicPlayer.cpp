#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <filesystem>

// Use C++17 filesystem if available
#if __cplusplus >= 201703L
namespace fs = std::filesystem;
#endif

#ifdef _WIN32
    #include <windows.h>
    #define CLEAR_COMMAND "cls"
    #define PLAY_COMMAND "start /min"
    #define STOP_COMMAND "taskkill /F /IM wmplayer.exe >nul 2>&1"
#else
    #include <unistd.h>
    #define CLEAR_COMMAND "clear"
    #define PLAY_COMMAND "flatpak run io.bassi.Amberol"
    #define STOP_COMMAND "pkill -f mpv || pkill -f vlc || pkill -f rhythmbox || pkill -f Amberol"
#endif

class Song {
private:
    std::string title;
    std::string artist;
    std::string filePath;
    int durationInSeconds;

public:
    Song(std::string title, std::string artist, std::string filePath, int duration)
        : title(title), artist(artist), filePath(filePath), durationInSeconds(duration) {}

    std::string getTitle() const { return title; }
    std::string getArtist() const { return artist; }
    std::string getFilePath() const { return filePath; }
    int getDuration() const { return durationInSeconds; }

    std::string getFormattedDuration() const {
        int minutes = durationInSeconds / 60;
        int seconds = durationInSeconds % 60;
        return std::to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + std::to_string(seconds);
    }
};

class Playlist {
private:
    std::string name;
    std::vector<Song> songs;

public:
    Playlist(std::string name) : name(name) {}

    void addSong(const Song& song) {
        songs.push_back(song);
    }

    void removeSong(int index) {
        if (index >= 0 && index < songs.size()) {
            songs.erase(songs.begin() + index);
        }
    }

    const std::vector<Song>& getSongs() const {
        return songs;
    }

    std::string getName() const {
        return name;
    }

    void setName(const std::string& newName) {
        name = newName;
    }

    int getTotalDuration() const {
        int total = 0;
        for (const auto& song : songs) {
            total += song.getDuration();
        }
        return total;
    }

    bool isEmpty() const {
        return songs.empty();
    }
};

class MusicPlayer {
private:
    std::vector<Playlist> playlists;
    int currentPlaylistIndex;
    int currentSongIndex;
    bool isPlaying;
    bool isPaused;

    void clearScreen() {
        std::system(CLEAR_COMMAND);
    }

public:
    MusicPlayer() : currentPlaylistIndex(-1), currentSongIndex(-1), isPlaying(false), isPaused(false) {
        // Create a default playlist
        playlists.push_back(Playlist("Default"));
        currentPlaylistIndex = 0;
    }

    void addPlaylist(const std::string& name) {
        playlists.push_back(Playlist(name));
    }

    void addSongToCurrentPlaylist(const Song& song) {
        if (currentPlaylistIndex >= 0 && currentPlaylistIndex < playlists.size()) {
            playlists[currentPlaylistIndex].addSong(song);
        }
    }

    void displayPlaylists() {
        clearScreen();
        std::cout << "===== PLAYLISTS =====" << std::endl;
        for (size_t i = 0; i < playlists.size(); i++) {
            std::cout << i + 1 << ". " << playlists[i].getName();
            if (i == currentPlaylistIndex) {
                std::cout << " (Current)";
            }
            std::cout << std::endl;
        }
        std::cout << "===================" << std::endl;
    }

    void selectPlaylist(int index) {
        if (index >= 0 && index < playlists.size()) {
            currentPlaylistIndex = index;
            currentSongIndex = -1;
            isPlaying = false;
            isPaused = false;
        }
    }

    void displayCurrentPlaylist() {
        clearScreen();
        if (currentPlaylistIndex >= 0 && currentPlaylistIndex < playlists.size()) {
            const Playlist& playlist = playlists[currentPlaylistIndex];
            const std::vector<Song>& songs = playlist.getSongs();
            
            std::cout << "===== PLAYLIST: " << playlist.getName() << " =====" << std::endl;
            std::cout << "Total Duration: " << formatDuration(playlist.getTotalDuration()) << std::endl;
            std::cout << "-------------------" << std::endl;
            
            for (size_t i = 0; i < songs.size(); i++) {
                std::cout << i + 1 << ". " << songs[i].getTitle() << " - " << songs[i].getArtist() 
                          << " (" << songs[i].getFormattedDuration() << ")";
                if (i == currentSongIndex) {
                    std::cout << " " << (isPaused ? "[PAUSED]" : "[PLAYING]");
                }
                std::cout << std::endl;
            }
            std::cout << "===================" << std::endl;
        } else {
            std::cout << "No playlist selected." << std::endl;
        }
    }

    void playSong(int index) {
        if (currentPlaylistIndex >= 0 && currentPlaylistIndex < playlists.size()) {
            const std::vector<Song>& songs = playlists[currentPlaylistIndex].getSongs();
            if (index >= 0 && index < songs.size()) {
                // Stop current playback if any
                if (isPlaying) {
                    std::system(STOP_COMMAND);
                }

                currentSongIndex = index;
                isPlaying = true;
                isPaused = false;

                // Play the song using the system's default media player
                std::string command = std::string(PLAY_COMMAND) + " \"" + songs[index].getFilePath() + "\"";
                std::system(command.c_str());

                displayNowPlaying();
            }
        }
    }

    void displayNowPlaying() {
        clearScreen();
        if (isPlaying && currentPlaylistIndex >= 0 && currentSongIndex >= 0) {
            const std::vector<Song>& songs = playlists[currentPlaylistIndex].getSongs();
            const Song& currentSong = songs[currentSongIndex];
            
            std::cout << "===== NOW PLAYING =====" << std::endl;
            std::cout << "Title: " << currentSong.getTitle() << std::endl;
            std::cout << "Artist: " << currentSong.getArtist() << std::endl;
            std::cout << "Duration: " << currentSong.getFormattedDuration() << std::endl;
            std::cout << "Playlist: " << playlists[currentPlaylistIndex].getName() << std::endl;
            std::cout << "Status: " << (isPaused ? "Paused" : "Playing") << std::endl;
            std::cout << "======================" << std::endl;
        } else {
            std::cout << "No song is currently playing." << std::endl;
        }
    }

    void pause() {
        if (isPlaying && !isPaused) {
            isPaused = true;
            #ifdef _WIN32
            // Windows pause command - generally not directly supported
            std::cout << "Playback paused (please use media player controls)." << std::endl;
            #else
            // Linux pause command - using DBUS to control the player
            std::system("dbus-send --print-reply --dest=org.mpris.MediaPlayer2.rhythmbox /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.Pause 2>/dev/null || "
                        "dbus-send --print-reply --dest=org.mpris.MediaPlayer2.vlc /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.Pause 2>/dev/null || "
                        "dbus-send --print-reply --dest=org.mpris.MediaPlayer2.Amberol /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.Pause 2>/dev/null");
            std::cout << "Playback paused." << std::endl;
            #endif
        }
    }

    void resume() {
        if (isPlaying && isPaused) {
            isPaused = false;
            #ifdef _WIN32
            // Windows resume command - generally not directly supported
            std::cout << "Playback resumed (please use media player controls)." << std::endl;
            #else
            // Linux resume command - using DBUS to control the player
            std::system("dbus-send --print-reply --dest=org.mpris.MediaPlayer2.rhythmbox /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.Play 2>/dev/null || "
                        "dbus-send --print-reply --dest=org.mpris.MediaPlayer2.vlc /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.Play 2>/dev/null || "
                        "dbus-send --print-reply --dest=org.mpris.MediaPlayer2.Amberol /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.Play 2>/dev/null");
            std::cout << "Playback resumed." << std::endl;
            #endif
        }
    }

    void stop() {
        if (isPlaying) {
            isPlaying = false;
            isPaused = false;
            std::system(STOP_COMMAND);
            std::cout << "Playback stopped." << std::endl;
        }
    }

    void nextSong() {
        if (currentPlaylistIndex >= 0 && currentSongIndex >= 0) {
            const std::vector<Song>& songs = playlists[currentPlaylistIndex].getSongs();
            if (currentSongIndex < songs.size() - 1) {
                playSong(currentSongIndex + 1);
            } else {
                std::cout << "End of playlist reached." << std::endl;
            }
        }
    }

    void previousSong() {
        if (currentPlaylistIndex >= 0 && currentSongIndex > 0) {
            playSong(currentSongIndex - 1);
        } else if (currentPlaylistIndex >= 0 && currentSongIndex == 0) {
            std::cout << "Beginning of playlist reached." << std::endl;
        }
    }

    bool importSongsFromFile(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Error: Could not open file " << filename << std::endl;
            return false;
        }

        std::string line;
        int importedCount = 0;
        while (std::getline(file, line)) {
            // Expect format: Title|Artist|FilePath|Duration
            size_t pos1 = line.find('|');
            size_t pos2 = line.find('|', pos1 + 1);
            size_t pos3 = line.find('|', pos2 + 1);

            if (pos1 != std::string::npos && pos2 != std::string::npos && pos3 != std::string::npos) {
                std::string title = line.substr(0, pos1);
                std::string artist = line.substr(pos1 + 1, pos2 - pos1 - 1);
                std::string filePath = line.substr(pos2 + 1, pos3 - pos2 - 1);
                
                // Verify the file exists (using C++17 filesystem if available)
                bool fileExists = false;
                #if __cplusplus >= 201703L
                fileExists = fs::exists(filePath);
                #else
                // Fallback for older C++ versions
                std::ifstream fileCheck(filePath);
                fileExists = fileCheck.good();
                fileCheck.close();
                #endif
                
                if (!fileExists) {
                    std::cerr << "Warning: File does not exist: " << filePath << std::endl;
                }
                
                try {
                    int duration = std::stoi(line.substr(pos3 + 1));
                    Song song(title, artist, filePath, duration);
                    addSongToCurrentPlaylist(song);
                    importedCount++;
                } catch (const std::exception& e) {
                    std::cerr << "Error parsing duration for song: " << title << " - " << e.what() << std::endl;
                }
            }
        }

        file.close();
        std::cout << "Imported " << importedCount << " songs from " << filename << std::endl;
        return importedCount > 0;
    }

    bool exportSongsToFile(const std::string& filename) {
        if (currentPlaylistIndex < 0 || currentPlaylistIndex >= playlists.size()) {
            return false;
        }

        std::ofstream file(filename);
        if (!file.is_open()) {
            return false;
        }

        const std::vector<Song>& songs = playlists[currentPlaylistIndex].getSongs();
        for (const auto& song : songs) {
            file << song.getTitle() << "|" << song.getArtist() << "|" 
                 << song.getFilePath() << "|" << song.getDuration() << std::endl;
        }

        file.close();
        return true;
    }

    std::string formatDuration(int seconds) {
        int hours = seconds / 3600;
        int minutes = (seconds % 3600) / 60;
        int secs = seconds % 60;
        
        std::string result;
        if (hours > 0) {
            result = std::to_string(hours) + ":";
            if (minutes < 10) result += "0";
        }
        
        result += std::to_string(minutes) + ":";
        if (secs < 10) result += "0";
        result += std::to_string(secs);
        
        return result;
    }
};

// Sample songs for demonstration
void addDemoSongs(MusicPlayer& player) {
    // These are dummy songs with Linux-style paths - in a real app, these would point to actual files
    player.addSongToCurrentPlaylist(Song("Bohemian Rhapsody", "Queen", "/home/user/Music/queen_bohemian_rhapsody.mp3", 354));
    player.addSongToCurrentPlaylist(Song("Hotel California", "Eagles", "/home/user/Music/eagles_hotel_california.mp3", 390));
    player.addSongToCurrentPlaylist(Song("Imagine", "John Lennon", "/home/user/Music/john_lennon_imagine.mp3", 183));
    player.addSongToCurrentPlaylist(Song("Billie Jean", "Michael Jackson", "/home/user/Music/michael_jackson_billie_jean.mp3", 294));
    player.addSongToCurrentPlaylist(Song("Smells Like Teen Spirit", "Nirvana", "/home/user/Music/nirvana_smells_like_teen_spirit.mp3", 301));
}

void displayMainMenu() {
    std::cout << "\n===== LINUX MUSIC PLAYER =====" << std::endl;
    std::cout << "1. View Playlists" << std::endl;
    std::cout << "2. View Current Playlist" << std::endl;
    std::cout << "3. Add New Song" << std::endl;
    std::cout << "4. Play Song" << std::endl;
    std::cout << "5. Pause/Resume" << std::endl;
    std::cout << "6. Stop" << std::endl;
    std::cout << "7. Next Song" << std::endl;
    std::cout << "8. Previous Song" << std::endl;
    std::cout << "9. Now Playing" << std::endl;
    std::cout << "10. Import Songs from File" << std::endl;
    std::cout << "11. Export Songs to File" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "===========================" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    MusicPlayer player;
    
    // System detection message
    #ifdef _WIN32
    std::cout << "Running on Windows system." << std::endl;
    #else
    std::cout << "Running on Linux system (optimized for Pop!_OS)." << std::endl;
    #endif
    
    std::cout << "Adding demo songs..." << std::endl;
    addDemoSongs(player);
    
    int choice;
    std::string input;
    
    while (true) {
        displayMainMenu();
        std::cin >> choice;
        std::cin.ignore(); // Clear the newline from the buffer
        
        switch (choice) {
            case 0:
                std::cout << "Exiting music player. Goodbye!" << std::endl;
                return 0;
            
            case 1: { // View Playlists
                player.displayPlaylists();
                std::cout << "Select a playlist (enter number): ";
                int playlistIndex;
                std::cin >> playlistIndex;
                std::cin.ignore();
                player.selectPlaylist(playlistIndex - 1);
                break;
            }
            
            case 2: // View Current Playlist
                player.displayCurrentPlaylist();
                std::cout << "Press Enter to continue...";
                std::getline(std::cin, input);
                break;
            
            case 3: { // Add New Song
                std::string title, artist, filePath;
                int duration = 0;
                
                std::cout << "Enter song title: ";
                std::getline(std::cin, title);
                
                std::cout << "Enter artist name: ";
                std::getline(std::cin, artist);
                
                std::cout << "Enter file path: ";
                std::getline(std::cin, filePath);
                
                std::cout << "Enter duration in seconds: ";
                std::cin >> duration;
                std::cin.ignore();
                
                player.addSongToCurrentPlaylist(Song(title, artist, filePath, duration));
                std::cout << "Song added successfully!" << std::endl;
                break;
            }
            
            case 4: { // Play Song
                player.displayCurrentPlaylist();
                std::cout << "Enter song number to play: ";
                int songIndex;
                std::cin >> songIndex;
                std::cin.ignore();
                player.playSong(songIndex - 1);
                break;
            }
            
            case 5: { // Pause/Resume
                char pauseChoice;
                std::cout << "Pause (p) or Resume (r)? ";
                std::cin >> pauseChoice;
                std::cin.ignore();
                
                if (pauseChoice == 'p' || pauseChoice == 'P') {
                    player.pause();
                } else if (pauseChoice == 'r' || pauseChoice == 'R') {
                    player.resume();
                }
                break;
            }
            
            case 6: // Stop
                player.stop();
                break;
            
            case 7: // Next Song
                player.nextSong();
                break;
            
            case 8: // Previous Song
                player.previousSong();
                break;
            
            case 9: // Now Playing
                player.displayNowPlaying();
                std::cout << "Press Enter to continue...";
                std::getline(std::cin, input);
                break;
            
            case 10: { // Import Songs
                std::string filename;
                std::cout << "Enter file name to import: ";
                std::getline(std::cin, filename);
                
                if (player.importSongsFromFile(filename)) {
                    std::cout << "Songs imported successfully!" << std::endl;
                } else {
                    std::cout << "Failed to import songs." << std::endl;
                }
                break;
            }
            
            case 11: { // Export Songs
                std::string filename;
                std::cout << "Enter file name to export: ";
                std::getline(std::cin, filename);
                
                if (player.exportSongsToFile(filename)) {
                    std::cout << "Songs exported successfully!" << std::endl;
                } else {
                    std::cout << "Failed to export songs." << std::endl;
                }
                break;
            }
            
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
        
        // Small delay for better user experience
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    
    return 0;
}