/* Exercise 1-19
 *
 * Write a function reverse(s) that reverses the character string
 * s. Use it to write a program that reverses its input a line at a
 * time.
 */

#include <stdio.h>

#define MAXLINE 1000

/* function prototypes */
int mygetline(char s[], int lim);
void myreverse(char s[]);

/* reverse each line input */
int main() {

    int len;
    char line[MAXLINE];
    
    while ((len = mygetline(line, MAXLINE)) > 0) {
	if (len > 0) {
	    myreverse(line);
	}
    }

    return 0;
}

/* read into character array s up until new line */
int mygetline(char s[], int lim) {

    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
	s[i] = c;
    }

    s[i] = '\0';

    return i;
}

/* get the length of a character array */
int mylength(char s[]) {

    int len;
    
    len = 0;
    while (s[len] != '\0') {
	++len;
    }

    return len;
}    

/* reverse character array */
void myreverse(char s[]) {

    int len;
    len = mylength(s);

    while (len >= 0) {
	putchar(s[len]);
	--len;
    }
    putchar('\n');
}
