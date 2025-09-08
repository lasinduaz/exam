#include <iostream>
#include <iomanip>
using namespace std;
float calcpayment(int Offpeak, int peak)
{

    float payment;

    // calculate off peak hours
    if (peak > 0 && peak <= 100)
    {
        payment = (float)peak * 45.00;
    }
    else if (peak > 101 && peak <= 200)
    {
        payment = (float)peak * 65.00;
    }
    else if (peak > 200)
    {
        payment = (float)peak * 90.00;
    }
    else
    {
        cout << "Invalid off peak hours" << endl;
        return -1;
    }

    // calculate peak hours
    if (Offpeak > 0 && Offpeak <= 100)
    {
        payment += (float)Offpeak * 45.00;
    }
    else if (Offpeak > 101 && Offpeak <= 200)
    {
        payment += (float)Offpeak * 65.00;
    }
    else if (peak > 200)
    {
        payment += (float)Offpeak * 90.00;
    }
    else
    {
        cout << "Invalid off peak hours" << endl;
        return -1;
    }

    return payment;
}
float calcservicecharge(int Offpeak, int peak)
{

    int totalunit;
    float servicecharge;
    totalunit = Offpeak + peak;

    if (totalunit > 0 && totalunit <= 150)
    {
        servicecharge = 600.00;
    }
    else if (totalunit > 150 && totalunit <= 250)
    {
        servicecharge = 700.00;
    }
    else if (totalunit > 250)
    {
        servicecharge = 1500.00;
    }
    else
    {
        cout << "Invalid off peak hours" << endl;
        return -1;
    }
    return servicecharge;
}
int main()
{

    float total_payment;
    float service_charge;
    int Offpeak, peak;

    cout << "Enter the number of off peak hours: ";
    cin >> Offpeak;
    cout << "Enter the number of peak hours: ";
    cin >> peak;

    total_payment = calcpayment(Offpeak, peak);
    service_charge = calcservicecharge(Offpeak, peak);

    cout << "Total Payment: " << fixed << setprecision(2) << total_payment << " LKR" << endl;
    cout << "Service Charge: " << fixed << setprecision(2) << service_charge << " LKR" << endl;
    cout << "Grand Total: " << fixed << setprecision(2) << total_payment + service_charge << " LKR" << endl;
}
