#include <iostream>
#include <string>
using namespace std;

struct Trip
{
    string destination;
    float distance; // KM
    double cost;    // in currency units
};

class Driver
{
private:
    string driverName;
    int driverID;
    Trip *tripList;
    int tripCount;
    double totalEarning;

public:
    // Default constructor
    Driver()
    {
        driverName = "";
        driverID = 0;
        tripCount = 0;
        totalEarning = 0;
        tripList = nullptr;
    }

    // Parameterized constructor
    Driver(string name, int id, int count, double TE)
    {
        driverName = name;
        driverID = id;
        tripCount = count;
        tripList = new Trip[tripCount];
        totalEarning = TE;
    }

    // Destructor
    ~Driver()
    {
        delete[] tripList;
    }

    void setDriveName(string Name)
    {
        driverName = Name;
    }
    string getDriveName()
    {
        return driverName;
    }
    void setDriverID(int DriId)
    {
        driverID = DriId;
    }
    int getDriveID()
    {
        return driverID;
    }

    void inputTrips()
    {
        cout << "=== Please Enter Driver's Information ===" << endl;
        cout << "Enter driver name: ";
        cin >> driverName;
        cout << "Enter driver ID: ";
        cin >> driverID;
        cout << "Enter number of trips: ";
        cin >> tripCount;

        delete[] tripList;
        tripList = new Trip[tripCount];

        cout << "== Trip Details == " << endl;
        for (int i = 0; i < tripCount; i++)
        {
            cout << "Trip " << i + 1 << ":\n";
            cout << "Destination: ";
            cin >> tripList[i].destination;
            cout << "Distance (km): ";
            cin >> tripList[i].distance;
            cout << "Cost (Rs): ";
            cin >> tripList[i].cost;
        }
    }

    double getTotalEarnings()
    {
        double total = 0.00;
        for (int i = 0; i < tripCount; i++)
        {
            total += tripList[i].cost;
        }
        return total;
    }

    void displayTrips()
    {
        cout << "\n=== Trip Summary ===\n";
        for (int i = 0; i < tripCount; i++)
        {
            cout << i + 1 << ". " << tripList[i].destination
                 << " - " << tripList[i].distance << " km - Rs. "
                 << tripList[i].cost << endl;
        }
    }
};

int main()
{
    Driver D1;
    D1.inputTrips();
    cout << "Total Earnings: Rs. " << D1.getTotalEarnings() << endl;
    D1.displayTrips();

    return 0;
}
