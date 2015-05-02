#include <stdio.h>

/* Exercise 1-13
 *
 * Write a program to print a histogram of the lengths of words in its
 * input. It is easy to draw a histogram with the bars horizontal; a
 * vertical orientation is more challenging.
 */

#define WORD 1
#define NOTWORD 0

main() {

    // initialise variables
    int c,j, i, nc, state;

    // don't care about words over 20 characters
    int wordlength[21];

    // initialise each wordlength in array to zero
    for (i = 1; i < 21; i++) {
	wordlength[i] = 0;
    }

    // set state and character count to zero
    state = nc = 0;
    
    while ((c = getchar()) != EOF) {

	// not a word
	if (c == ' ' || c == '\n' || c == '\t') {
	    state = NOTWORD;

	    // even though the current state is not in a word it make
	    // sense that a word has already been found, so check the
	    // character count and add it to the array
	    if (nc > 0) {
	      ++wordlength[nc];
	    }

	    // reset character count
	    nc = 0;
	}

	// found a word
	else if (state == NOTWORD) {
	    state = WORD;
	}

	// count characters in word
	if (state == WORD) {
	    ++nc;
	}
	
    }
    
    for (i = 1; i < 21; ++i) {
	printf("%2d ", i);
	for (j = 0; j < wordlength[i]; ++j) {
	    printf("#");
	}
	printf("\n");
    }
}
