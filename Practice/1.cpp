#include <iostream>
#include <iomanip>
using namespace std;

// A
void inputSales(int sales[5])
{
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter sales for salesperson " << (i + 1) << ": ";
        cin >> sales[i];
    }
}

// B
int findMaxSales(int sales[5])
{
    int MaxSales = sales[0];
    for (int i = 1; i < 5; i++)
    {
        if (sales[i] > MaxSales)
        {
            MaxSales = sales[i];
        }
    }
    return MaxSales;
}

// C
int findMinSales(int sales[5])
{
    int MinSales = sales[0];
    for (int i = 1; i < 5; i++)
    {
        if (sales[i] < MinSales)
        {
            MinSales = sales[i];
        }
    }
    return MinSales;
}

// D
void calcCommission(int sales[5], float Commission[5])
{
    for (int i = 0; i < 5; i++)
    {
        if (sales[i] > 5000)
        {
            Commission[i] = 0.6f * sales[i];
        }
        else
        {
            Commission[i] = 0.4f * sales[i];
        }
    }
}

int main()
{
    int sales[5];
    int MaxSales;
    int MinSales;
    float Commission[5] = {0};

    cout << "=== Sales Data Entry ===" << endl;
    inputSales(sales);

    MaxSales = findMaxSales(sales);
    MinSales = findMinSales(sales);
    calcCommission(sales, Commission);

    cout << "\n=== Sales Summary ===" << endl;
    cout << "Maximum Sales: " << MaxSales << endl;
    cout << "Minimum Sales: " << MinSales << endl;

    cout << "\n+--------------+----------+------------+" << endl;
    cout << "| Salesperson  |  Sales   | Commission |" << endl;
    cout << "+--------------+----------+------------+" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "| "
             << setw(11) << left << (i + 1) << " | "
             << setw(8) << right << sales[i] << " | "
             << setw(10) << fixed << setprecision(2) << Commission[i] << " |" << endl;
    }
    cout << "+--------------+----------+------------+" << endl;
    return 0;
}
