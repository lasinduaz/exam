#include <iostream>
using namespace std;
int main()
{

    int num;
    cout << "number :";
    cin >> num;

    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= i; j++)
        {
           if (j == 1 || j == i || i == num) 
            {
                cout << " * ";
            }
            else
            {
                cout << "  ";
            }
        }
        cout << endl;
    }
    return 0;
}