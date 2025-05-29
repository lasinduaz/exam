#include <iostream>
#include <cmath>
using namespace std;

int main(){

    //A
    int array1[7] = {2 ,4,6, 8, 10, 12, 14};
    int array2[7];
    int array3[7];

    //B
    //make squre of array1
    for (int i = 0;i <7;i++){
        array2[i] = pow(array1[i],2);
    }
    cout << endl;
    cout << "The square of the first array is: " << endl;
    for (int i = 0; i < 7; i++) {
        cout << " Here is the square of " << array1[i] << " = " << array2[i] << endl;
    }


    //C
    cout << endl;
    cout << "array1 + array2 = " << endl;
    for (int i = 0;i< 7;i++){
        array3[i] = array1[i] + array2[i];
        cout << " Here is the sum of " << array1[i] << " + " << array2[i] << " = " << array3[i] << endl;
    }

    //D
    cout << endl;
    cout << "Index\t" << "Value\t" << endl;
    for (int i =0; i < 7;i++){
        
        cout << i << "\t" << array3[i] << "\t" << endl;
    }
    
return 0;
}