/*
 * Exercise 6-1
 *
 * Our version of getword does not properly handle underscores, string
 * constants, comments, or preprocessor control lines. Write a better version.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100 /* max length of a word */

/* key: a structure that holds both a word and the number of times
 * that word appears
 */
struct key {
  char *word;
  int count;
};

/* keytab: an array of key structures */
struct key keytab[] = {
    "#define", 0,
    "#include", 0,
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "unsigned", 0,
    "size_t", 0,
    "void", 0,
    "volatile", 0,
    "while", 0,
};

/* the number of keys found in keytab (sizeof returns size of any
 * object) 
 */
#define NKEYS (sizeof keytab / sizeof(keytab[0]))

int checkchar(char first);
int getword(char *, int);
int binsearch(char *, struct key *, int);
int mygetch(void);
void myungetch(int);

/* count C keywords */
main() {

    int n;
    char word[MAXWORD];

    /* read into word at most of MAXWORD length */
    while (getword(word, MAXWORD) != EOF) {

        /* if first chracter of word is a letter or "#" or "/*" */
        if (checkchar(word[0])) {

            /* do binary search in keytab of word */
            if ((n = binsearch(word, keytab, NKEYS)) >= 0) {
                /* if found, increment count for word */
                keytab[n].count++;
            }
        }
    }

    /* loop over each keyword */
    for (n = 0;  n < NKEYS; n++) {
        /* if a keyword was found, print count and word */
        if (keytab[n].count > 0) {
            printf("%4d %s\n",
               keytab[n].count, keytab[n].word);
        }
    }

    return 0;
}

/* checkchar: check to see if character falls within a certain search
 * criteria.
 */
int checkchar(char ch) {

    char c[] = "#_";

    int i;
    for (i = 0; i < sizeof(c); i++) {
        if (ch == c[i]) {
            return 1;
        }
    }

    if (isalpha(ch)) {
        return 1;
    }

    return 0;
}

/* binsearch: find word in tab[0]...tab[n-1] */
int binsearch(char *word, struct key tab[], int n) {

    int cond;
    int low, high, mid;

    low = 0;
    high = n -1;

    while (low <= high) {
        mid = (low+high) / 2;
        if ((cond = strcmp(word, tab[mid].word)) < 0) {
            high = mid - 1;
        }
        else if (cond > 0) {
            low = mid + 1;
        }
        else {
            return mid;
        }
    }

    return -1;
}

/* getword: get next word or character from input */
int getword(char *word, int lim) {

    int c, mygetch(void);
    void myungetch(int);

    char *w = word;

    /* skip spaces if not comment */
    while (isspace(c = mygetch())) {
        ;
    }

    /* read into word if not EOF */
    if (c != EOF) {
        *w++ = c;
    }

    /* check first character */
    if (!checkchar(c)) {
	    *w = '\0';
	    return c;
    }

    /* scan rest of word */
    for (; --lim > 0; w++) {
        /* if character search fails */
        if (!checkchar(*w = mygetch())) {
            /* push chracter back */
            myungetch(*w);
            break;
        }
    }

    /* terminate word*/
    *w = '\0';

    return word[0];
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

/* get a (possibly pushed-back) character */
int mygetch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push character back on input */
void myungetch(int c) {
    
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    }
    else {
        buf[bufp++] = c;
    }
}
