#include <iostream>
#include <iomanip>
using namespace std;
int main()
{

    int *pPointer;
    int age = 21;

    // declare pointer
    pPointer = &age;
    cout << "Here is pointer variable called 'age': " << pPointer << endl;
    // int pointer= &pPointer;

    cout << "Value pointed to by pointer: " << *pPointer << endl;
    cout << setw(10) << 12345678910LL << endl;
    cout << setw(30) << 12345678910LL << endl;
    std::cout << std::setw(500) << 123 << std::endl;
return 0;
}