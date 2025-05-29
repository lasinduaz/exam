#include <iostream>
using namespace std;

struct Service {
    string description;
    double price;
};

class Vehicle {
private:
    string ownerName;
    string vehicleNumber;
    int serviceCount;
    Service* services; // dynamic array of services

public:
    Vehicle() {
        ownerName = "";
        vehicleNumber = "";
        serviceCount = 0;
        services = nullptr;
    }

    ~Vehicle() {
        delete[] services; // free dynamically allocated memory
    }

    void getInput() {
        cout << "Enter owner's name: ";
        cin.ignore(); // clear input buffer
        getline(cin, ownerName);

        cout << "Enter vehicle number: ";
        getline(cin, vehicleNumber);

        cout << "Enter number of services: ";
        cin >> serviceCount;

        services = new Service[serviceCount]; // dynamic array

        for (int i = 0; i < serviceCount; ++i) {
            cout << "Enter description for service " << i + 1 << ": ";
            cin.ignore();
            getline(cin, services[i].description);

            cout << "Enter cost for service " << i + 1 << ": ";
            cin >> services[i].price;
        }
    }

    double calculateTotalCost() {
        double total = 0;
        for (int i = 0; i < serviceCount; ++i) {
            total += services[i].price;
        }
        return total;
    }

    void display() {
        cout << "\n--- Vehicle Service Summary ---" << endl;
        cout << "Owner: " << ownerName << endl;
        cout << "Vehicle No: " << vehicleNumber << endl;
        cout << "Services:\n";
        for (int i = 0; i < serviceCount; ++i) {
            cout << i + 1 << ". " << services[i].description << " - Rs. " << services[i].price << endl;
        }
        cout << "Total Service Cost: Rs. " << calculateTotalCost() << endl;
    }
};

int main() {
    Vehicle v;
    v.getInput();
    v.display();
    return 0;
}
