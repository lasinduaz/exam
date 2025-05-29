#include <iostream>
#include <string>
using namespace std;

// Online Order Processing System
struct Order {
    string quantityName;
    int quantity;
    double price;
};

class Customer {
private:
    string name;
    int customerID;
    Order* order_list;
    int ordercount;

public:
    // Constructor
    Customer() {
        name = "";
        customerID = 0;
        ordercount = 0;
        order_list = NULL; // Use nullptr if using C++11 or newer
    }

    // Destructor to avoid memory leaks
    ~Customer() {
        delete[] order_list;
    }

    // Getters
    string getName() {
        return name;
    }

    int getCustomerID() {
        return customerID;
    }

    int getOrderCount() {
        return ordercount;
    }

    // Setters
    void setName(string Name) {
        name = Name;
    }

    void setCustomerID(int custID) {
        customerID = custID;
    }

    void setOrderCount(int ordCount) {
        ordercount = ordCount;
    }

    // Function to input orders
    void inputOrders() {
        cout << "Please Enter Name: ";
        cin >> name;

        cout << "Please Enter your ID: ";
        cin >> customerID;

        cout << "Please Enter Your Order Count: ";
        cin >> ordercount;

        order_list = new Order[ordercount];

        cout << "== Please Enter Order Details ===" << endl;
        for (int i = 0; i < ordercount; i++) {
            cout << "\nOrder #" << i + 1 << endl;
            cout << "Enter item name: ";
            cin >> order_list[i].quantityName;
            cout << "Enter quantity: ";
            cin >> order_list[i].quantity;
            cout << "Enter price: ";
            cin >> order_list[i].price;
        }
    }
};

int main() {
    cout << "? Program started successfully.\n";

    Customer C1;
    C1.inputOrders();

    return 0;
}

