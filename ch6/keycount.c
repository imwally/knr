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
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0,
    "#define", 0,
    "size_t", 0,
};

/* the number of keys found in keytab (sizeof returns size of any
 * object) 
 */
#define NKEYS (sizeof keytab / sizeof(keytab[0]))

int getword(char *, int);
int binsearch(char *, struct key *, int);

/* count C keywords */
main() {

    int n;
    char word[MAXWORD];

    /* read into word at most of MAXWORD length */
    while (getword(word, MAXWORD) != EOF) {

	/* if first chracter of word is a letter */
	if (isalpha(word[0])) {

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

    int c, getch(void);
    void ungetch(int);

    char *w = word;

    /* skip spaces */
    while (isspace(c = getch())) {
	;
    }

    /* read into word if not EOF */
    if (c != EOF) {
	*w++ = c;
    }

    /* terminate word and return c if first character of the word is
     * not a letter
     */
    if (c != '#' && !isalpha(c)) {
	*w = '\0';
	return c;
    }

    /* scan rest of word */
    for (; --lim > 0; w++) {
	/* if a non-alphabetic, non-numeric charcter is found */
	if (c != '#' && !isalnum(*w = getch())) {
	    /* push chracter back */
	    ungetch(*w);
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
