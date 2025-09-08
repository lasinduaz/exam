#include <iostream>
using namespace std;
int main()
{
    int douDimArray[3][3] = {
        {1, 2, 4},
        {5, 6, 9},
        {7, 6, 8}};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << douDimArray[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}