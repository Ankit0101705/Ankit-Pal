#include <stdio.h>

void celsiusToFahrenheitAndKelvin(float celsius) {
    float fahrenheit = (celsius * 9 / 5) + 32;
    float kelvin = celsius + 273.15;
    printf("\n%.2f Celsius is equivalent to:\n", celsius);
    printf("Fahrenheit: %.2f\n", fahrenheit);
    printf("Kelvin: %.2f\n", kelvin);
}

void fahrenheitToCelsiusAndKelvin(float fahrenheit) {
    float celsius = (fahrenheit - 32) * 5 / 9;
    float kelvin = celsius + 273.15;
    printf("\n%.2f Fahrenheit is equivalent to:\n", fahrenheit);
    printf("Celsius: %.2f\n", celsius);
    printf("Kelvin: %.2f\n", kelvin);
}

void kelvinToCelsiusAndFahrenheit(float kelvin) {
    float celsius = kelvin - 273.15;
    float fahrenheit = (celsius * 9 / 5) + 32;
    printf("\n%.2f Kelvin is equivalent to:\n", kelvin);
    printf("Celsius: %.2f\n", celsius);
    printf("Fahrenheit: %.2f\n", fahrenheit);
}

int main() {
    int choice;
    float temperature;

    printf("Temperature Converter\n");
    printf("1. Convert Celsius to Fahrenheit and Kelvin\n");
    printf("2. Convert Fahrenheit to Celsius and Kelvin\n");
    printf("3. Convert Kelvin to Celsius and Fahrenheit\n");
    printf("Enter your choice (1-3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            printf("Enter temperature in Celsius: ");
            scanf("%f", &temperature);
            celsiusToFahrenheitAndKelvin(temperature);
            break;
        case 2:
            printf("Enter temperature in Fahrenheit: ");
            scanf("%f", &temperature);
            fahrenheitToCelsiusAndKelvin(temperature);
            break;
        case 3:
            printf("Enter temperature in Kelvin: ");
            scanf("%f", &temperature);
            kelvinToCelsiusAndFahrenheit(temperature);
            break;
        default:
            printf("Invalid choice! Please run the program again.\n");
    }

    return 0;
}


