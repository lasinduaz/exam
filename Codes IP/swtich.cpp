#include <iostream>
using namespace std;
int main()
{

    cout << "Please Enter the Day :";
    int num;
    cin >> num;

    switch (num)
    {

    case 1:
        cout << "Monday";
        break;
    case 2:
        cout << "Thusday";
        break;
    case 3:
        cout << "Wensday";
        break;
    case 4:
        cout << "Thusday";
        break;
    case 5:
        cout << "Frinday";
        break;
    case 6:
        cout << "Sataday";
        break;
    case 7:
        cout << "Sunday";
        break;
    default:
        if (num > 8)
        {
            cout << "There only 7 days in week";
            break;
        }
        else
        {
            cout << "Here is samething Wrong";
        }
        break;
    }
    return 0;
}