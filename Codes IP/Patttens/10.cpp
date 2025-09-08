#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

    int num;
    cin >> num;

    for (int i = 0; i < num; i++)
    {
        // Print leading spaces
        for (int space = 0; space < num - i - 1 ; space++)
        {
            cout << "  "; // Two spaces for alignment
        }

        // caculate print number
        int number = 1;
        for (int j = 0; j <= i; j++)
        {
            cout << setw(3) << number;
            // calculate number
            number = number * (i - j) / (j + 1);
        }
        cout << endl;
    }
    return 0;
}