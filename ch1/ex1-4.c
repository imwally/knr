#include <stdio.h>

/* Exercise 1-4
 *
 * Write a program to print the corresponding Celsius to Fahrenheit table.
 */

main() {
  float fahr, celsius;
  float lower, upper, step;

  lower = 0;    /* lower limit of temperature scale */
  upper = 300;  /* upper limit */
  step = 20;    /* step size*/

  printf("Celsius \tFahrenheit\n");
  
  celsius = lower;
  while (celsius <= upper) {
    fahr = (9.0/5.0) * celsius+32;
    printf("%7.1f \t%10.1f\n", celsius, fahr);
    celsius = celsius + step;
  }
}
