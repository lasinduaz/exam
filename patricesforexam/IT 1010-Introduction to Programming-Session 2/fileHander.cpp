#include <iostream>
#include <fstream>
using namespace std;

int main(){


    ofstream outFile ("output.txt");
     if (outFile.is_open()){
        outFile << "Hello World!" << endl;
        outFile << "This is a test file." << endl;
        outFile.close();

     }
        else{
            cout << "Unable to open file";
        }
    return 0;
}