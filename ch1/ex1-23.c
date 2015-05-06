/* Exercise 1-23
 * 
 * Write a program to remove all comments from a C program. Don't
 * forget to handle quoted strings and character constants properly. C
 * comments don't nest.
 */

#include <stdio.h>

#define MAXLINE 1000
#define IN  1
#define OUT 0

int mygetline(char s[], int lim);
void stripcomments(char s[]);

int main() {

    int i, len, max;
    char line[MAXLINE];

    max = i = 0;
    while ((len = mygetline(line, MAXLINE)) > 0) {
	if (len > 0) {
	    /* will only strip single comment lines */
	    stripcomments(line);
	}
    }

    return 0;
}

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

void stripcomments(char s[]) {

    int i;

    i = 0;
    while (s[i] != '\0') {
	if (s[i] == '/' && s[i+1] == '*') {
	    i = i + 2;
	    while (s[i] != '*' && s[i+1] != '/') {
		++i;
	    }
	    i = i + 2;
	} 
	else {
	    putchar(s[i]);
	    ++i;
	}
    }
}
