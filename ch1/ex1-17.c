/* Exercise 1-17
 *
 * Write a program to print all input lines that are longer than 80
 * characters.
 */

#include <stdio.h>

#define MAXLINE 100
#define LENGTH  81      /* add 1 to compensate for null character */

int main() {

    int len;             /* length of the current line */
    char line[MAXLINE];  /* only read up to 100 characters */
    
    while ((len = getlinenew(line, MAXLINE)) > 0) {
	if (len > LENGTH) {
	    printf("%s\n", line);
	}
    }

    return 0;
}

int getlinenew(char s[], int lim) {

    int c, i;

    // read characters into c if character is not EOF or a new line
    // and less than the limit
    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
	// copy character into array s at index i
	s[i] = c;
    }

    // check for blanks lines (else program would terminate on new line)
    if (c == '\n') {
	s[i] = c;
	++i;
    }

    // add null character to end of array to mark the end of the string
    s[i] = '\0';

    // return line length
    return i;
}
