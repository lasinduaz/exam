#include <iostream>
using namespace std;
float Calcpayment(char brickType, int noBricks)
{

    if (brickType == 's' || brickType == 'S')
    {

        return noBricks * 40;
    }
    else if (brickType == 'L' || brickType == 'l')
    {
        return noBricks * 80;
    }
    else if (brickType == 'C' || brickType == 'c')
    {
        return noBricks * 100;
    }
    else
    {
        cout << "Invalid brick type" << endl;
        return 0;
    }
}
float calcAdditionalpayment(char unloading, char transportation)
{

    float additional_payment = 0;
    if (unloading == 'Y' || unloading == 'y')
    {
        additional_payment += 100;
    }

    cout << "Enter the distance to be travelled in km ?";
    cin >> transportation;
    if (transportation == 'Y' || transportation == 'y')
    {
        additional_payment += transportation * 100;
    }
    return additional_payment;
}
int main()
{

    float inital_payment = 0;
    float additional_payment = 0;

    // Input for brick details
    cout << "Enter the type of brick (S for Small, L for Large, C for Custom): ";
    char brickType;
    cin >> brickType;
    cout << "Enter the number of bricks: ";
    int noBricks;
    cin >> noBricks;
    // Input for additional payment details
    cout << "Is unloading required? (Y/N): ";
    char unloading;
    cin >> unloading;
    cout << "Is transportation required? (Y/N): ";
    char transportation;
    cin >> transportation;

    // Calculate payments
    inital_payment = Calcpayment(brickType, noBricks);
    additional_payment = calcAdditionalpayment(unloading, transportation);
    float net_payment = inital_payment + additional_payment;
    // Display the total payment
    cout << "The total payment is: " << net_payment << endl;
    cout << "The initial payment is: " << inital_payment << endl;
    cout << "The additional payment is: " << additional_payment << endl;


    return 0;
}