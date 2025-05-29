#include <iostream>
using namespace std;

// functions
void InputValues(float *sub_P_Marks, float *sub_Q_Marks, int size)
{
    cout << " === Dinput User Inputs  ===" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter Marks For Subject P:";
        cin >> sub_P_Marks[i];
    }
    cout << endl;
    for (int j = 0; j < size; j++)
    {
        cout << "Enter Marks For Subject Q:";
        cin >> sub_Q_Marks[j];
    }
    cout << endl;
}

float MinimumValue(float *sub_P_Marks, float *sub_Q_Marks)
{
    float minValue_P = sub_P_Marks[0];
    float minValue_Q = sub_Q_Marks[0];

    for (int i = 1; i < 5; i++)
    {
        if (sub_P_Marks[i] < minValue_P)
        {
            minValue_P = sub_P_Marks[i];
        }
        if (sub_Q_Marks[i] < minValue_Q)
        {
            minValue_Q = sub_Q_Marks[i];
        }
    }
    if (minValue_P < minValue_Q)
    {
        return minValue_P;
    }
    else
    {
        return minValue_Q;
    }
}
float MaximumValue(float *sub_P_Marks, float *sub_Q_Marks)
{
    float maxValue_P = sub_P_Marks[0];
    float maxValue_Q = sub_Q_Marks[0];

    for (int i = 1; i < 5; i++)
    {
        if (sub_P_Marks[i] > maxValue_P)
        {
            maxValue_P = sub_P_Marks[i];
        }
        if (sub_Q_Marks[i] > maxValue_Q)
        {
            maxValue_Q = sub_Q_Marks[i];
        }
    }
    if (maxValue_P > maxValue_Q)
    {
        return maxValue_P;
    }
    else
    {
        return maxValue_Q;
    }
}
float AvgMarks(float *sub_P_Marks, float *sub_Q_Marks)
{
    float total = 0;
    for (int i = 0; i < 5; i++)
    {
        total += sub_P_Marks[i];
        total += sub_Q_Marks[i];
    }
    return total / 10;
}

int main()
{

    float sub_P_Marks[5];
    float sub_Q_Marks[5];

    InputValues(sub_P_Marks, sub_Q_Marks, 5);

    float minValue = MinimumValue(sub_P_Marks, sub_Q_Marks);
    float maxValue = MaximumValue(sub_P_Marks, sub_Q_Marks);
    float avg = AvgMarks(sub_P_Marks, sub_Q_Marks);
    cout << " === Display Result ===" << endl;

    cout << "Class\tSubject P\tSubject Q\tMinimum\tMaximum\tTotal\tAverage" << endl;

    return 0;
}