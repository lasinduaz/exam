#include <cstdlib>
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    int no1 = atoi(argv[1]);
    int no2 = atoi(argv[2]);
    int no3 = atoi(argv[3]);
    int sum = no1 + no2 + no3;

    cout << "Sun is " << sum;

    return 0;
}