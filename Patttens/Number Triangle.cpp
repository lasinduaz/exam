#include <iostream>
using namespace std;
int main()
{

    cout << "Enter Number :";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }

        cout << endl;
    }
    return 0;
}