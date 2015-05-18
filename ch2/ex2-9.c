/* Exercise 2-9
 *
 * In a two's complement number system, x &= (x-1) deletes the
 * rightmost 1-bit in x. Explain why. Use this observation to write a
 * faster version of bitcount.
 */

#include <stdio.h>

int bitcount(unsigned x);
int fastbitcount(unsigned x);

int main() {

    unsigned x = 227;

    printf("%d\n", bitcount(x));
    printf("%d\n", fastbitcount(x));
    
    return 0;
}

/* fastbitcount: count 1 bits in x faster */
int fastbitcount(unsigned x) {

    int b;
    for (b = 1; (x &= (x-1)) != 0; b++) {
	;
    }

    return b;
}

/* bitcount: count 1 bits in x */
int bitcount(unsigned x) {

    int b;

    /* shift x to the right by one on each loop until no bits are
     * left 
     */
    for (b = 0; x != 0; x >>= 1) {
	/* x & 01 will return true if a 1 is in the LSB of x */
	if (x & 01) {
	    b++;
	}
    }

    return b;
}
