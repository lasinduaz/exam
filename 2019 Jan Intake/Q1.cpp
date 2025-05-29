#include <iostream>
using namespace std;
void inputMarks(float classA[5], float classB[5])
{

    // For Class A
    cout << " === Enter Inputs for ClASS A ===" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter Marks For Student " << i + 1 << " in Class A: ";
        cin >> classA[i];
        while (classA[i] < 0 || classA[i] > 100)
        {
            cout << "Invalid Marks. Please enter again: ";
            cin >> classA[i];
        }
    }

    // For Class B
    cout << " === Enter Inputs For Class B ===" << endl;
    for (int j = 0; j < 5; j++)
    {
        cout << "Enter Marks For Student " << j + 1 << " in Class B: ";
        cin >> classB[j];
        while (classB[j] < 0 || classB[j] > 100)
        {
            cout << "Invalid Marks. Please enter again: ";
            cin >> classB[j];
        }
    }
}
void MinmumMarks(float classA[5], float classB[5], float &MinA, float &MinB)
{

    for (int i = 1; i < 5; i++)
    {

        if (classA[i] < MinA)
        {
            MinA = classA[i];
        }
        if (classB[i] < MinB)
        {
            MinB = classB[i];
        }
    }
}

void MaximumMarks(float classA[5], float classB[5], float &MaxA, float &MaxB)
{

    for (int i = 1; i < 5; i++)
    {
        if (classA[i] > MaxA)
        {
            MaxA = classA[i];
        }
        if (classB[i] > MaxB)
        {
            MaxB = classB[i];
        }
    }
}
void TotalMarks(float classA[5], float classB[5], float &TotalA, float &TotalB)
{

    for (int i = 0; i < 5; i++)
    {
        TotalA += classA[i];
        TotalB += classB[i];
    }
}

void AvarageMarks(float classA[5], float classB[5], float &TotalA, float &TotalB, float &AvgA, float &AvgB)
{

    for (int i = 0; i < 5; i++)
    {
        AvgA += classA[i];
        AvgB += classB[i];
    }
    AvgA = AvgA / 5;
    AvgB = AvgB / 5;
}
int main()
{

    float classA[5], classB[5];
    float TotalA = 0, TotalB = 0;
    float AvgA = 0, AvgB = 0;

    inputMarks(classA, classB);

    float MinA = classA[0];
    float MinB = classB[0];

    float MaxA = classA[0];
    float MaxB = classB[0];

    cout << "" << endl;
    cout << " === Here for Class A ===" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "Marks For Student " << i + 1 << " in Class A: " << classA[i] << endl;
    }
    cout << " === Here for Class B ===" << endl;

    for (int j = 0; j < 5; j++)
    {
        cout << "Marks For Student " << j + 1 << " in Class B: " << classB[j] << endl;
    }
    for (int i = 0; i < 5; i++)
    {
        TotalA += classA[i];
        TotalB += classB[i];
    }
    MinmumMarks(classA, classB, MinA, MinB);
    MaximumMarks(classA, classB, MaxA, MaxB);
    TotalMarks(classA, classB, TotalA, TotalB);

    cout << "" << endl;
    cout << "" << "Minimum Marks For Class A: " << MinA << endl;
    cout << "" << "Minimum Marks For Class B: " << MinB << endl;
    cout << "" << endl;
    cout << "" << "Maximum Marks For Class A: " << MaxA << endl;
    cout << "" << "Maximum Marks For Class B: " << MaxB << endl;
    cout << "" << endl;
    cout << "" << "Total Marks For Class A: " << TotalA << endl;
    cout << "" << "Total Marks for Class B: " << TotalA << endl;
    cout << "" << endl;
    cout << "" << "Average Marks For Class A: " << AvgA << endl;
    cout << "" << "Average Marks For Class B: " << AvgB << endl;
    cout << "" << endl;
    cout << "" << "total Marks For Class A: " << TotalA << endl;
    cout << "" << "total Marks For Class B: " << TotalB << endl;
    cout << "" << endl;
    return 0;
}