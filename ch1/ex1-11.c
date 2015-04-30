#include <stdio.h>

/* Exercise 1-11
 *
 * How would you test the word count program? What kinds of input are
 * most likely to uncover bugs if there are any?
 */

#define IN   1  /* inside a word */
#define OUT  0  /* outside a word */

/* count lines, words, and characters in input */
main() {

    int c, nl, nc, nw, state;

    state = OUT;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF) {
	++nc;
	if (c == '\n') {
	    ++nl;
	}
	// There is no special character check. Anything that is not
	// the following is considered a word. Writing the actual
	// escape characters are counted as words.
	if (c == ' ' | c == '\n' || c == '\t') {
	    state = OUT;
	}
	else if (state == OUT) {
	    state = IN;
	    ++nw;
	}
    }
    printf("%d %d %d\n", nl, nw, nc);
}
