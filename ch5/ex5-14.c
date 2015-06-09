/* Exercise 5-14
 *
 * Modify the sort program to handle a -r flag, which indicates
 * sorting in reverse (decreasing) order. Besure that -r works with
 * -n.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000      /* max length of line*/
#define MAXLINES 5000    /* max #lines to be sorted */
char *lineptr[MAXLINES]; /* pointers to text lines */

int mygetline(char *s, int lim);
int readines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int reverse);

void myqsort(void *lineptr[], int left, int right,
	   int (*comp)(void *, void *));
int numcmp(char *, char*);

/* sort input lines */
main(int argc, char *argv[]) {

    int nlines;       /* number of input lines read */
    int numeric = 0;  /* 1 if numeric sort */
    int reverse = 0;  /* 1 if reverse sort */
    
    while (--argc > 0) {
	if (strcmp(argv[argc], "-n") == 0) {
	    numeric = 1;
	}
	if (strcmp(argv[argc], "-r") == 0) {
	    reverse = 1;
	}
    }
    

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
	myqsort((void**) lineptr, 0, nlines-1,
	      (int (*)(void*, void*)) (numeric ? numcmp : strcmp));
	writelines(lineptr, nlines, reverse);
	return 0;
    }

    else {
	printf("input too big to sort\n");
	return 1;
    }
}

/* myqsort: sort v[left]...v[right] into increasing order
 *
 * Explanation of arguments:
 *
 * void *v[]: array of pointers of void
 * int left: left number to compare
 * int right: right number to compare
 * int (*comp)(void *, void *): comp is a pointer to a 
 * function that takes two void * arguments and returns an int
 */
void myqsort(void *v[], int left, int right,
	   int (*comp)(void *, void *)) {

    int i, last;

    void swap(void *v[], int, int);

    if (left >= right) {
	return;
    }

    swap(v, left, (left + right)/2);

    last = left;

    for (i = left+1; i <= right; i++) {
	if ((*comp)(v[i], v[left]) < 0) {
	    swap(v, ++last, i);
	}
    }

    swap(v, left, last);
    myqsort(v, left, last-1, comp);
    myqsort(v, last+1, right, comp);
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2) {

    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);

    if (v1 < v2) {
	return -1;
    }
    else if (v1 > v2) {
	return 1;
    }
    else {
	return 0;
    }
}

/* swap: swap i an j */
void swap(void *v[], int i, int j) {

    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
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
void writelines(char *lineptr[], int nlines, int reverse) {

    while (nlines-- > 0) {
	printf("%s\n", (reverse ? lineptr[nlines] : *lineptr++));
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
