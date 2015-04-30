#include <stdio.h>

/* Exercise 1-9
 *
 * Write a program to copy its input to its output, replace each
 * string of one or more blanks by a single blank.
 */

main() {

    int c;
    
    while ((c = getchar()) != EOF) {
	// Look for a blank.
	if (c == ' ') {
	    // If there are more blanks, ignore them.
	    while ((c = getchar()) == ' ') {
		c = 0;
	    }
	    // Finally add a single blank.
	    putchar(' ');
	}
	putchar(c);
    }
}
