#include <iostream>
#include <cassert>
using namespace std;

// A
float calcpayment(float medicalcharge, int type, int days, double payment)
{

    payment = 0;
    // calculate Accommodation
    float accommodation = 0;
    if (type == 1)
    {
        accommodation = 17000;
    }
    else if (type == 2)
    {
        accommodation = 25000;
    }
    else if (type == 3)
    {
        accommodation = 35000;
    }
    else
    {
        cout << "Invalid type" << endl;
        return -1;
    }
    // calculate medical charge
    payment = medicalcharge + (accommodation * days);
    return payment;
}

// B
float calcDiscount(char seniorcitizen, char loyaltyMember,float total_payment)
{
    float discount = 0;
    if (seniorcitizen == 'Y' || seniorcitizen == 'y'){
        discount += 0.05 * total_payment;
    }
    if (loyaltyMember == 'Y' || loyaltyMember == 'y'){
        discount += 0.15 * total_payment;
    }
    return discount;
}

void testcalcpayment()
{
    // Test case 1: Valid inputs
    float result1 = calcpayment(15000, 1, 3, 0);
    assert(result1 == 15000 + (17000 * 3)); // Expected result: 15000 + (17000 * 3)

    // Test case 2: Invalid type
    float result2 = calcpayment(15000, 4, 3, 0);
    assert(result2 == -1); // Expected result: -1 for invalid type

    cout << "All test cases passed for calcpayment()" << endl;
}

int main()
{

    float total_payment;
    float total_discount;
    char seniorcitizen;
    char loyaltyMember;


    //calling function A
    total_payment = calcpayment(15000+ 12000, 1, 3, 0);
    //calling function B
    total_discount=calcDiscount('Y', 'Y', total_payment);
    //calling test function
    testcalcpayment();

    cout << "Total payment  = " << total_payment << endl;
    cout << "Total discount = " << total_discount << endl;
    cout << "Final payment  = " << total_payment - total_discount << endl;
    cout << "Thank you for using our service" << endl;
    return 0;
}