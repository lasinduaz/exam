#include <iostream>
using namespace std;
int main()
{
    int num;
    cout << "Enter the space :";
    cin >> num;

    // print as raw and coloum
    for (int i = 1; i <= num; i++)
    {
        // print spaces
        for (int s = 1; s <= num - i; s++)
        {
            cout << " ";
        }
        for (int k = 0; k <= i; k++)
        {
            cout << " * ";
        }
        cout << "" << endl;
    }
    return 0;
}