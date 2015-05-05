/* Exercise 1-20
 *
 * Write a program 'detab' that replaces tabs in the input with the
 * proper number of blanks to space to the next tab stop. Assume a
 * fixed set of tab stops, say every n columns. Should n be a variable
 * or a symbolic parameter?
 */

#include <stdio.h>

#define MAXLINE 1000
#define TABWIDTH 10

int mygetline(char s[], int lim);
void detab(char s[]);

int main() {

    int len;
    char line[MAXLINE];
    
    while ((len = mygetline(line, MAXLINE)) > 0) {
	if (len > 0) {
	    detab(line);
	}
    }

    return 0;
}

/* read line into s and return length */
int mygetline(char s[], int lim) {

    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
	s[i] = c;
    }

    if (c == '\n') {
	s[i] = c;
	++i;
    }

    s[i] = '\0';

    return i;
}

/* detab takes a character array and replaces each tab (\t) with the
 * amount of spaces specified by MAXTAB.
 *
 * note: detab does not strip consecutive tabs, if 2 tabs are found,
 * MAXTAB*2 spaces replace it
 */
void detab(char s[]) {

    int c, i, j;

    i = 0;
    while (s[i] != '\0') {
	if (s[i] == '\t') {
	    for (j = 0; j < TABWIDTH; ++j) {
		putchar(' ');
	    }
	    ++i;
	}
	else {
	    putchar(s[i]);
	    ++i;
	}
    }
}
