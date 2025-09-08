#include <iostream>
using namespace std;
int main()
{

    int num;
    cin >> num;

    for (int i = 1; i <= num; i++)
    {
        for (int j = 1; j <= num; j++)
        {
            // First or last row → all stars
            // First or last column → star
            if (i == 1 || i == num || j == 1 || j == num)
            {
                cout << "* ";
            }
            else
            {
                cout << "  "; // spaces between border stars
            }
        }
        cout << endl;
    }
    return 0;
}