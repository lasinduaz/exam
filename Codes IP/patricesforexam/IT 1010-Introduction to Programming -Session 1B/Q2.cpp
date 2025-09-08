#include <iostream>
using namespace std;


int main(){

    //A
    int array1[7];
    int array2[7];
    int array3[7];


    //B
    for (int i = 0; i < 7; i++) {
        cout << "Enter Array 1 : " << "[" << i << "]" << " : ";
        cin >> array1[i];
    }

    //C
    // C: Copy elements from array1 to array2 in reverse order
    for (int i = 0; i < 7; i++) {
        array2[i] = array1[6 - i]; // Reverse copy
    }
    for (int i = 0; i < 7; i++) {
        cout << "Array 2 : " << "[" << i << "]" << " : " << array2[i] << endl;
    }
    //D 
    for (int i = 0;i < 7; i++){

        array3[i] = array1[i] * array2[i];
    }

    //D
      for (int i = 0;i < 7; i++){

        cout << array3[i] << endl;
    }
    return 0;
}