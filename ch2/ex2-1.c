/* Exercise 2-1
 *
 * Write a program to determine the ranges of char, short, int, and
 * long varibles, both signed and unsigned, by printing apporpriate
 * values from standard headers and by direct computation. Harder if
 * you compute them: determine the ranges of the various
 * floating-point types.
 */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {

    /* char  */
    printf("\nchar\n----------------------------\n");
    printf("CHAR_MIN: %5d\n",   CHAR_MIN);
    printf("CHAR_MAX: %5d\n\n", CHAR_MAX);

    /* unsigned char */
    printf("unsigned char\n----------------------------\n");
    printf("UCHAR_MAX: %5d\n\n", UCHAR_MAX);

    /* signed char */
    printf("signed char\n----------------------------\n");
    printf("SCHAR_MIN: %5d\n",   SCHAR_MIN);
    printf("SCHAR_MAX: %5d\n\n", SCHAR_MAX);

    /* short */
    printf("short\n----------------------------\n");
    printf("SHRT_MIN: %8d\n",   SHRT_MIN);
    printf("SHRT_MAX: %8d\n\n", SHRT_MAX);

    /* unsigned short */
    printf("unsigned short\n----------------------------\n");
    printf("USHRT_MAX: %8d\n\n", USHRT_MAX);

    /* int */
    printf("int\n----------------------------\n");
    printf("INT_MIN: %12d\n",   INT_MIN);
    printf("INT_MAX: %12d\n\n", INT_MAX);

    /* unsigned int */
    printf("unsigned int\n----------------------------\n");
    printf("UINT_MAX: %12d\n\n", UINT_MAX);

    /* long */
    printf("long\n----------------------------\n");
    printf("LONG_MIN: %lu\n",   LONG_MIN);
    printf("LONG_MAX: %lu\n\n", LONG_MAX);
    
    /* unsigned long */
    printf("unsigned long\n----------------------------\n");
    printf("ULONG_MAX: %lu\n\n", ULONG_MAX);
    
}
