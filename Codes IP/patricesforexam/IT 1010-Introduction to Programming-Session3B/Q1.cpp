#include <iostream>
using namespace std;

int main()
{

    char first;
    char second;
    int numbers;

    cout << "Please enter the first character: ";
    cin >> first;
    cout << "Enter the secound character : ";
    cin >> second;
    cout << "Enter the number of lines : ";
    cin >> numbers;

    
    for (int i = numbers; i >= 0; i--){
            cout << first << " ";
    }
    for (int i = 0; i < numbers; i++){
            cout << second << " ";
    }
    cout << endl;


    return 0;
}