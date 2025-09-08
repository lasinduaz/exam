#include <iostream>
using namespace std;
int main(){

    cout << " Number :";
    int num;
    cin >> num;
    for (int i = 0; i < num;i++){
        for (int j = 0; j < i; j++){
            cout << " * ";
        }
        cout <<  endl;
    }
    return 0;
}