#include <iostream>
using namespace std;
struct student {
    
    string name;
    int age;
    float gpa;
    bool gender;

};

void addvalues(student &s1){

    student s1;

    cout << "Enter Name ";
    cin >>s1.name;
    cout << "Enter Age ";
    cin >>s1.age;
    cout << "Enter GPA ";
    cin >>s1.gpa;
    
    cout << endl;;
    cout << "Name: " << s1.name << endl;

}
int main(){

    student s1;
    addvalues(s1);
    cout << "Name: " << s1.name << endl;

    return 0;
}