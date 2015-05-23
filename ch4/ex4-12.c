/* Exercise 4-12
 *
 * Adapt the ideas of printd to write a recursive version of itoa;
 * that is, convert an integer into a string by calling a recursive
 * routine.
 */

#include <stdio.h>

int main() {
    
    void itoa(int n, char s[]);
    char numbers[10];
    
    itoa(4634921, numbers);
    printf("%s\n", numbers);
}

void itoa(int n, char s[]) {

    static int i;
    i = 0;

    if (n < 0) {
	n = -n;
    }

    if (n / 10) {
	itoa(n / 10, s);
    }

    s[i++] = n % 10 + '0';
    s[i] = '\0';
}
