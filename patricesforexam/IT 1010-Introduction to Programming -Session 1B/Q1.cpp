#include <iostream>
using namespace std;
int main(){

    int num;
    cout << "Enter The Number Of Rowes: ";
    cin >> num;
    
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (i == j || i + j == num - 1) {
                cout << "*"; // Print '*' for diagonal positions
            } else {
                cout << " "; // Print space for non-diagonal positions
            }
        }
        cout << endl; // Move to the next row
    }




    return 0;
}