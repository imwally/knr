/* Exercise 5-1
 *
 * As written, getint treats a + or - not followed by a digit as a
 * valid representation of zero. Fix it to push such a character back
 * on the input.
 */

#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100
#define SIZE 10

int getch(void);
void ungetch(int);

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */

int main(void) {

    int n, array[SIZE], getint(int *);

    /* initialise array to zeros */
    for (n = 0; n < SIZE; n++) {
	array[n] = 0;
    }

    /* read ints into array */
    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++) {
	;
    }

    /* print ints in array */
    printf("\n----\n");
    for (n = 0; n < SIZE; n++) {
	printf("%d... %d\n", n, array[n]);
    }
    
}

/* getint: get next integer from input into *pn */
int getint(int *pn) {

    int c, sign;

    /* skip white space */
    while (isspace(c = getch())) {
	;
    }

    /* it is not a number */
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
	ungetch(c);
	return 0;
    }

    /* set sign */
    sign = (c == '-') ? -1 : 1;

    /* read + and - chars */
    if (c == '+' || c == '-') {
	/* if char after + or - is not a digit unget it */
	if (!isdigit(c = getch())) {
	    ungetch(c);
	    return 0;
	}
    }

    /* if c is a digit continue to read c and set *pn to the integer
     * representation */
    for (*pn = 0; isdigit(c); c = getch()) {
	*pn = 10 * *pn + (c - '0');
    }

    /* set *pn to pos or neg depending on sign */
    *pn *= sign;
    
    if (c != EOF) {
	ungetch(c);
    }

    return c;
}

/* get a (possibly pushed-back) character */
int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void ungetch(int c) {
    if (bufp >= BUFSIZE) {
	printf("ungetch: too many characters\n");
    }
    else {
	buf[bufp++] = c;
    }
}


