#include <iostream>
using namespace std;

class LastClass {
private:
    string firstName;
    string lastName;
    int age;
    bool gender;
    string momName;

public:
    string schoolName;
    string schoolDistrict;
    int studentCount;
    float avgGpa;

    // setters
    void setFirstName(const string& fname) {
        firstName = fname;
    }
    void setLastName(const string& lname) {
        lastName = lname;
    }
    void setAge(int a) {
        age = a;
    }
    void setGender(bool g) {
        gender = g;
    }
    void setMomName(const string& mName) {
        momName = mName;
    }

    // getters
    string getFirstName() const {
        return firstName;
    }
    string getLastName() const {
        return lastName;
    }
    int getAge() const {
        return age;
    }
    bool getGender() const {
        return gender;
    }
    string getMomName() const {
        return momName;
    }
};

int main() {
    LastClass lc1;
    string fname, lname, momName;
    bool gender;
    int age;

    cout << "============Starting=============" << endl;
    cout << "Enter First Name: ";
    cin >> fname;
    cout << "Enter Last Name: ";
    cin >> lname;
    cout << "Enter Age: ";
    cin >> age;
    cout << "Enter Gender (0 for Female, 1 for Male): ";
    cin >> gender;
    cout << "Mom Name: ";
    cin >> momName;

    lc1.setFirstName(fname);
    lc1.setLastName(lname);
    lc1.setAge(age);
    lc1.setGender(gender);
    lc1.setMomName(momName);

    cout << "=======Printing==================" << endl;
    cout << "First Name: " << lc1.getFirstName() << endl;
    cout << "Last Name: " << lc1.getLastName() << endl;
    cout << "Age: " << lc1.getAge() << endl;
    cout << "Gender: " << (lc1.getGender() ? "Male" : "Female") << endl;
    cout << "Mom Name: " << lc1.getMomName() << endl;

    return 0;
}
