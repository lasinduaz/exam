#include <iostream>
#include <string>
using namespace std;
/*
typedef struct
{

    string Name;
    int age, grade;
    bool gender;
} student;

typedef struct
{
    string Title;
    string anthor;
    int Print_year;

} Book;

int main()
{

    student s1;
    Book B1;

    cout << "Enter the Title of the Book: ";
    getline(cin, B1.Title);

    cout << "Enter the Author of the Book: ";
    getline(cin, B1.anthor);

    cout << "Enter the Year of Publication: ";
    cin >> B1.Print_year;
    cin.ignore(); // Clear newline from buffer

    cout << "Enter the Name of the Student: ";
    getline(cin, s1.Name);

    cout << "Enter Age: ";
    cin >> s1.age;

    cout << "Enter Grade: ";
    cin >> s1.grade;

    cout << "Enter Gender (1 for Male, 0 for Female): ";
    cin >> s1.gender;

    cout << "\n--- Book Details ---" << endl;
    cout << "Title: " << B1.Title << endl;
    cout << "Author: " << B1.anthor << endl;
    cout << "Year: " << B1.Print_year << endl;

    cout << "\n--- Student Details ---" << endl;
    cout << "Name: " << s1.Name << endl;
    cout << "Age: " << s1.age << endl;
    cout << "Grade: " << s1.grade << endl;
    cout << "Gender: " << (s1.gender ? "Male" : "Female") << endl;

    return 0;
}
   */
#include <iostream>
#include <string.h>
using namespace std;
struct dog
{
    string name;
    int age;
    string color;
};
int main()
{
    struct dog my_dog = {"Benji", 5, "Brown"};
    /* declaring pointer to dog structure */
    struct dog *ptr_dog;
    /* assigning the starting memory address of the
    instance my_dog to the ptr_dog pointer */
    ptr_dog = &my_dog;
    /* changing the value pointed by the pointer to a new value */
    ptr_dog->name = "Tommy";
    cout << "Dog's name: " << ptr_dog->name << endl;
    cout << "Dog's age: " << ptr_dog->age << endl;
    cout << "Dog's color:" << ptr_dog->color << endl;
    return 0;
}
