#include <stdio.h>

/* Exercise 1-8
 *
 * Write a program to count blanks, tabs, and newlines.
 */

main() {

    int c, blank, tab, newline;

    blank = 0;
    tab = 0;
    newline = 0;

    while ((c = getchar()) != EOF) {
	if (c  == ' ') {
	    ++blank;
	}

	if (c == '\t') {
	    ++tab;
	}

	if (c == '\n') {
	    ++newline;
	}
    }

    printf("\nBlanks: %d, Tabs: %d, Newlines: %d\n", blank, tab, newline);
}
