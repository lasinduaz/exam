#include <iostream>
using namespace std;
int main()
{

    int n;
    cin >> n;

    cout << "======" << endl;
    for (int i = 0; i < n; i++)
    {
        /*        // print spacees
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "  ";
        }
            */

        for (int k = 0; k < i; k++)
        {
            cout << " *";
        }
        cout << endl;
    }

    return 0;
}