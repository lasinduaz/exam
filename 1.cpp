#include <cstdlib>
#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
    cout << rand() << endl;
    srand(time(0));
    cout << rand() << endl;
    cout << endl;
    cout << "Enter a Number :";
    int num;
    cin >> num;
    cout << "Here is abslute of number :" << abs(num);
    return 0;
}