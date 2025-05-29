#include <iostream>
using namespace std;

float avg(int a, int b)
{
    return (a + b) / 2.0;
}

float sum(int a, int b)
{
    return a + b;
}

float divide(int a, int b)
{
    return float(a) / b;
}

int main()
{
    int a, b;

    cout << "==============================" << endl;
    cout << "      Function Overloading    " << endl;
    cout << "==============================" << endl << endl;

    cout << ">> Average Calculations:" << endl;
    cout << "   avg(10, 20) = " << avg(10, 20) << endl;
    cout << "   avg(10, 30) = " << avg(10, 30) << endl << endl;

    cout << ">> Sum Calculations:" << endl;
    cout << "   sum(10, 20) = " << sum(10, 20) << endl;
    cout << "   sum(10, 30) = " << sum(10, 30) << endl << endl;

    cout << ">> Division Calculations:" << endl;
    cout << "   divide(10, 20) = " << divide(10, 20) << endl;
    cout << "   divide(10, 30) = " << divide(10, 30) << endl;

    cout << "==============================" << endl;

    return 0;
}