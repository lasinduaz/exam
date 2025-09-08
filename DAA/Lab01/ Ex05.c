#include <stdio.h>

int main() {
    float fahrenheit, celsius;

    printf("Fahrenheit\tCelsius\n");

    for (fahrenheit = 0; fahrenheit <= 200; fahrenheit += 20) {
        celsius = 5.0 / 9.0 * (fahrenheit - 32);
        printf("%.0f\t\t%.0f\n", fahrenheit, celsius);
    }

    return 0;
}