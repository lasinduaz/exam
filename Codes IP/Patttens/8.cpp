#include <iostream>
using namespace std;
int main()
{

    int num;
    cin >> num;
    for (int i = 1; i < num; i++)
    {
        for (int j = 1; j < num; j++)
        {
            cout << (i * j);
            cout.width(10);
        }
        cout << endl;
    }
    return 0;
}