#include <stdio.h>

int main()
{

    int num1, num2, sum;

    printf("Enter Two Integers :");
    scanf("%d %d", &num1, &num2);

    sum = num1 + num2;

    // Print the sum to stdout
    printf("Sum = %d\n", sum);
    return 0;
}