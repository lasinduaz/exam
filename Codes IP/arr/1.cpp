#include <iostream>
using namespace std;
int main(){

    cout << "Here is single size array" << endl;
    int singledimi[3] = {1,3,4}; // specify the size of the array
    for (int i = 0;i < 3;i++)
    {
        cout << singledimi[i] << "\t";
    }
    return 0;
}