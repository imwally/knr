/* Exercise 1-23
 * 
 * Write a program to remove all comments from a C program. Don't
 * forget to handle quoted strings and character constants properly. C
 * comments don't nest.
 */

#include <stdio.h>

#define MAXCODE 2000
#define IN  1
#define OUT 0

int getcode(char s[], int lim);
void stripcomments(char code[], char stripped[]);

int main() {

    int i, len, max;
    char code[MAXCODE];
    char stripped[MAXCODE];

    while ((len = getcode(code, MAXCODE)) > 0) {
	stripcomments(code, stripped);
    }
    
    printf("%s\n", stripped);
    return 0;
}

int getcode(char s[], int lim) {
    
    int c, i;
    
    i = 0;
    while (i < lim-1 && (c = getchar()) != EOF) {
	s[i] = c;
	++i;
    }

    s[i] = '\0';

    return i;
}

/* stripcomments takes code, removes comments, and copies into
 * stripped 
 *
 * note: does not strip // comments
 */
void stripcomments(char code[], char stripped[]) {

    int i, j, x;

    i = j = x = 0;

    while (code[i] != '\0') {

	/* found the beginning of a comment */
	if (code[i] == '/' && code[i+1] == '*') {
	    x = 1;
	    i = i + 2;
	}

	/* while in a comment */
	while (x == 1) {

	    /* found end of comment */
	    if (code[i] == '*' && code[i+1] == '/') {
		x = 0;
		i = i + 2;
	    }
	    ++i;
	}

	/* add to stripped if not in a comment */
	if (x == 0) {
	    stripped[j] = code[i];
	    ++j;
	    ++i;
	}
    }

}
