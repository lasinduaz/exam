#include <iostream>
#include <iomanip>

using namespace std;
int main(int argc, char* argv[])
{

    char arrg[6];
    /*    for (int i = 0; i < 6; i++)
    {

        cout << "Input a leter of a word " << i + 1 << " :";
        cin >> arrg[i];
    }
    */

    for (int i = 0; i < argc; i++)
    {

        cout << setw(10) << argv[i];
    }
    cout << endl;

    return 0;
}