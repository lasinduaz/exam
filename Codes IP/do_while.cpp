#include <iostream>
using namespace std;
int main()
{
    /*
    int num ;
    int counter = 0;
    do
    {
        cout << "Number :";
        cin >> num;
        counter ++;

    } while (num < 5);
    int num2;
    cin >> num2;
    while (num2 > 0)
    {
        cout << num2 << "\t";
        num2--;
    }

    return 0;
    */
    for (int i = 0; i < 10; i++)
    {
        if (i == 4)
        {
            break;;
        }
        cout << i << "\n";
    }
}