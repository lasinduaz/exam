#include <iostream>
#include <string>
using namespace std;
struct Course
{
    string Coursename;
    int Marks;
};
class Student
{
private:
    int StudentID;
    string Name;
    Course courses[3];
    int avg;

public:
    void getInputes()
    {
        cout << "=== Enter Student Details ===" << endl;
        cout << "Enter Student ID: ";
        cin >> StudentID;
        cout << "Enter Student Name: ";
        cin >> Name;
        cout << "=== Enter Course Details ===" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "Course " << i + 1 << " Name: ";
            cin.ignore();
            getline(cin, courses[i].Coursename);
            cout << "Course " << i + 1 << " Marks: ";
            cin >> courses[i].Marks;
        }
    }
    float calculateAverage()
    {
        int sum = 0;
        for (int i = 0; i < 3; i++)
        {
            sum += courses[i].Marks;
        }
        avg = sum / 3;
        return avg;
    }

    void displayData()
    {
        cout << "\n=== Student Result ===" << endl;
        cout << "Student ID: " << StudentID << endl;
        cout << "Student Name: " << Name << endl;
        cout << "Courses and Marks:" << endl;
        for (int i = 0; i < 3; i++)
        {
            cout << "  Course " << i + 1 << ": " << courses[i].Coursename
                 << " | Marks: " << courses[i].Marks << endl;
        }
        cout << "Average Marks: " << avg << endl;
    }
};

int main()
{

    Student S1;
    S1.getInputes();
    S1.calculateAverage();
    S1.displayData();
    return 0;
}