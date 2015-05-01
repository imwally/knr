#include <stdio.h>

/* Exercise 1-12
 *
 * Write a program that prints its input one word per line.
 */

main() {

    int c;

    while ((c = getchar()) != EOF) {
	// This will add as many new lines as spaces or tabs.
	if (c == ' ' || c == '\t') {
	    putchar('\n');
	}
	else {
	    putchar(c);
	}
    }
}
