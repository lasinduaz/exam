#include <iostream>
using namespace std;
int main()
{

    int a = 10;
    int b = 20;
    int c = 30;

    int *pa = &a;
    int *pb = &b;
    int *pc = &c;

    cout << "A :" << a << " Pointer is :" << pa << endl;
    cout << "B :" << b << " Pointer is :" << pb << endl;
    cout << "C :" << c << " Pointer is :" << pc << endl;
    
    // assign values using pointers
    *pa = 100;
    *pb = 200;
    *pc = 300;

    cout << "After assignment:" << endl;
    cout << "A :" << a << " Pointer is :" << pa << endl;
    cout << "B :" << b << " Pointer is :" << pb << endl;
    cout << "C :" << c << " Pointer is :" << pc << endl;

    return 0;
}