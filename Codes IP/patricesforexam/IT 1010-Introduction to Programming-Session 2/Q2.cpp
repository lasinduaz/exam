#include <iostream>
using namespace std;
int main(){


//A
int arr1[5][5];

//B
for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j < j++){
            cout << "Enter Number for " << i << "." << j << " :";
            cin >> arr1[i][j];
        }

    }

//C
for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
        cout << arr1[i][j] << "\t";
    }
    cout << endl;
}
//D
// Mirror the matrix (horizontal flip)
for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5 / 2; j++) {
        // Swap elements in the row
        int temp = arr1[i][j];
        arr1[i][j] = arr1[i][4 - j];
        arr1[i][4 - j] = temp;
        cout << "" << endl;
        cout << temp << "\t";
    }
}
return 0;
}