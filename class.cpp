#include <iostream>
using namespace std;
class lastclass{
    public:
        string firstName;
        string lastName;
        int age;
        float gpa;
        bool gender;

        lastclass(string firstNamem ,string lastName, int age, float gpa,bool gender){
            firstName = firstNamem;
            lastName= lastName;
            age = age;
            gpa = gpa;
            gender = gender;
        }
};

void addValues(lastclass &lc1) {
    cout << "===== Enter Student Details =====" << endl;
    cout << "First Name  : ";
    cin >> lc1.firstName;
    cout << "Last Name   : ";
    cin >> lc1.lastName;
    cout << "Age         : ";
    cin >> lc1.age;
    cout << "GPA         : ";
    cin >> lc1.gpa;
    cout << "Gender (0 for Female, 1 for Male): ";
    cin >> lc1.gender;
    cout << "=================================" << endl;
}
int main(){

    // The original code tries to use a default constructor and a member function that don't exist.
    // Fix: Create an object with the required constructor, then call the standalone addValues function.

    lastclass lc1("", "", 0, 0.0f, false); // Provide initial values as required by the constructor
    addValues(lc1); // Use the standalone function to input values

    cout << endl;
    cout << "===== Student Details =====" << endl;
    cout << "First Name  : " << lc1.firstName << endl;
    cout << "Last Name   : " << lc1.lastName << endl;
    cout << "Age         : " << lc1.age << endl;
    cout << "GPA         : " << lc1.gpa << endl;
    cout << "Gender      : " << (lc1.gender ? "Male" : "Female") << endl;
    cout << "===========================" << endl;

    return 0;
}