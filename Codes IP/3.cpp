#include <iostream>
#include <string>
using namespace std;

class vehical
{
private:
    string model;
    string brand;
    int year;
    float price;

public:
    // ✅ Default constructor
    vehical()
    {
        model = "";
        brand = "";
        year = 0;
    }

    void inputData()
    {
        // vehical v;
        cout << " === Enter the Inputs === " << endl;
        cout << "Enter the model:";
        cin >> model;
        cout << "Enter the brand :";
        cin >> brand;
        cout << "Enter the year :";
        cin >> year;
        cout << "Enter the price :";
        cin >> price;
    }
    void displayData()
    {

        cout << " === Result === " << endl;
        cout << "Model of the car : " << model << endl;
        cout << "Brand of the car :" << brand << endl;
        cout << "Year of the car :" << year << endl;
        cout << "Price of the car " << price << endl;
    }
};

int main()
{
    vehical v;
    v.inputData();
    v.displayData();

    return 0;
}