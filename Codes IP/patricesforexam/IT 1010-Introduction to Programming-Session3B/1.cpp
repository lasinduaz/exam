#include <iostream>
using namespace std;

// Function to calculate payment based on brick type and number of bricks
float Calcpayment(char brickType, int noBricks) {
    if (noBricks < 0) {
        cout << "Invalid number of bricks. Must be non-negative." << endl;
        return 0;
    }

    if (brickType == 's' || brickType == 'S') {
        return noBricks * 40;
    } else if (brickType == 'L' || brickType == 'l') {
        return noBricks * 80;
    } else if (brickType == 'C' || brickType == 'c') {
        return noBricks * 100;
    } else {
        cout << "Invalid brick type" << endl;
        return 0;
    }
}

// Function to calculate additional payment based on unloading and transportation
float calcAdditionalpayment(char unloading, int distance) {
    float additional_payment = 0;

    if (unloading == 'Y' || unloading == 'y') {
        additional_payment += 100;
    }

    if (distance < 0) {
        cout << "Invalid distance. Must be non-negative." << endl;
        return 0;
    }

    additional_payment += distance * 100; // Add transportation cost based on distance
    return additional_payment;
}

int main() {
    char brickType, unloading;
    int noBricks, distance;

    // Input for brick details
    cout << "Enter the type of brick (S for Small, L for Large, C for Custom): ";
    cin >> brickType;
    cout << "Enter the number of bricks: ";
    cin >> noBricks;

    // Input for additional payment details
    cout << "Is unloading required? (Y/N): ";
    cin >> unloading;
    cout << "Enter the distance to be travelled in km: ";
    cin >> distance;

    // Calculate payments
    float initial_payment = Calcpayment(brickType, noBricks);
    float additional_payment = calcAdditionalpayment(unloading, distance);
    float net_payment = initial_payment + additional_payment;

    // Display the total payment
    cout << "The total payment is: " << net_payment << endl;

    return 0;
}