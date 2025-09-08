#include <iostream>
using namespace std;
int main()
{

    // A Declare a 2D array
    int transdetails[3][3];

    // B Declare get inputs
    for (int i = 0; i < 3; i++){
    cout << "Enter details for customer " << i + 1 << " " << endl;
    cout << "" << endl;
    cout << "Enter the total amount of money   :";
    cin >> transdetails[i][0];
    cout << "Enter the total withdrawal amount :";
    cin >> transdetails[i][1];
    cout << "Enter the withdrawal linit        :" << endl;
    cin >> transdetails[i][2];
    if (transdetails[i][2] < transdetails[i][1]){
        cout << "The withdrawal limit is less than the amount to be withdrawn" << endl;
        cout << "Please enter the correct amount" << endl;
        cin >> transdetails[i][2];

    }

    //C
    for (int i = 0; i < 3; i++){

        cout << transdetails[i][0] << " " << "\t";
        cout << transdetails[i][1] << " "<< "\t";
        cout << transdetails[i][2] << " "<< "\t" << endl;
    }

    return 0;
}