#include <stdio.h>

/* Exercise 1-10
 *
 * Write a program to copy its input to its output, replacing each tab
 * by \t, each backspace by \b, and each backslash by \\. This makes
 * tabs and backspaces visible in an unambiguous way.
 */

main() {

    int c;

    while((c = getchar()) != EOF) {

	if (c == '\t') {
	    printf("\\t");
	    c = 0;
	}

	// Terminal will hijack input therefore backspaces are never
	// passed to the program.
	//
	// Need to research buffered vs. unbuffered I/O.
	if (c == '\b') {
	    printf("\\b");
	    c = 0;
	}
	
	if (c == '\\') {
	    printf("\\");
	}

	putchar(c);
    }
}
