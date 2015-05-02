#include <stdio.h>

/* Exercise 1-15
 * 
 * Rewrite the temperature conversion program to use a function for
 * conversion.
 */

#define MAXTEMP 300
#define STEP    20

// Celsius to Fahrenheit
float ctof(float celsius)
{
    return (9.0/5.0) * celsius+32;
}

// Fahrenheit to Celsius
float ftoc(float fahrenheit)
{
    return (5.0/9.0) * (fahrenheit-32.0);
}

main()
{

    float i;

    printf("Fahrenheit\tCelsius\n");
    while (i <= MAXTEMP) {
	printf("%10.0f %12.1f\n", i, ftoc(i));
	i = i + STEP;
    }

    return 0;
}


