#include <iostream>
using namespace std;
int main()
{

    char x = 'a';
    char *p = &x;

    cout << "Value of x: " << x << endl;
    cout << "Address of x: " << &x << endl;
    cout << "Value of p: " << p << endl;

    int y = 10;
    int *q = &y; // q points to y
    *q = 20;     // changes y to 20
/*
    struct Student {
        string name;
    };

    Student s1;
    Student *ps = &s1; // ps points to s1
    ps->name = "Ali";  // modifies s1.name
*/      
    string food = "Pizza";

    string like= "10";
   // string &like = food; // like points to food
    like = "Burger"; // modify the value of food through the reference
    cout << "Value of food: " << food << endl;


    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr; // Pointer to the first element of the array

    cout << "Using pointer arithmetic:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "ptr + " << i << " points to address: " << (ptr + i) 
             << " with value: " << *(ptr + i) << endl;
    }

    cout << "\nUsing array indexing:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "&arr[" << i << "] points to address: " << &arr[i] 
             << " with value: " << arr[i] << endl;
    }
    return 0;
}
