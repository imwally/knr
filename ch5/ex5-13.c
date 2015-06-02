/* Exercise 5-13
 *
 * Write the program tail, which prints the last n lines of its
 * input. By default, n is set to 10, let us say, but it can be
 * changed by an optional argument so that
 *
 * tail -n
 * 
 * prints the last n lines.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000 /* max #lines to be stored in lineptr */
#define MAXLEN 1000   /* max length of any input line */

char *lineptr[MAXLINES];

int mygetline(char *s, int lim);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

main(int argc, char *argv[]) {

    int c, tail, nlines;
    char line[MAXLINES];

    /* default number of last lines to print */
    tail = 10;

    /* check for optional tail argument number */
    while (--argc > 0 && (*++argv)[0] == '-') {
	c = *++argv[0];
	if (isdigit(c)) {
	    argc = 0;
	    tail = atoi(*argv);
	}
	else {
	    printf("tail: illegal option %c\n", c);
	    return 1;
	}
    }

    /* read up to MAXLINES into lineptr */
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {

	/* less lines were read than tail so print all */
	if (nlines < tail) {
	    writelines(lineptr, nlines);
	}

	/* otherwise only print the last tail number of lines */
	else {
	    writelines(lineptr+(nlines-tail), tail);
	}
	
	return 0;
    }

    else {
	printf("error: input too big\n");
	return 1;
    }
    
}

/* mygetline: read line into s */
int mygetline(char *s, int lim) {

    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
	*s++ = c;
    }

    if (c == '\n') {
	*s++ = c;
	++i;
    }

    *s = '\0';

    return i;
}

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines) {

    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = mygetline(line, MAXLEN)) > 0) {
	if (nlines >= maxlines || (p = malloc(len)) == NULL) {
	    return -1;
	}
	else {
	    line[len-1] = '\0';
	    strcpy(p, line);
	    lineptr[nlines++] = p;
	}
    }

    return nlines;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines) {

    while (nlines-- > 0) {
	printf("%s\n", *lineptr++);
    }
}
