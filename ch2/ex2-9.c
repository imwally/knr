/* Exercise 2-9
 *
 * In a two's complement number system, x &= (x-1) deletes the
 * rightmost 1-bit in x. Explain why. Use this observation to write a
 * faster version of bitcount.
 *
 * Explanation:
 * 
 * In a two's complement number system the right most bit denotes the
 * 1's place. This bit will never be occupied in an even number:
 *
 * 0010 = 2
 * 0100 = 4
 * 0110 = 6
 *
 * If the number happens to be odd:
 *
 * 0001 = 1
 * 0011 = 3
 * 0101 = 5
 * 0111 = 7
 *
 * Then subtracting 1 and &'ing it with itself will drop the rightmost
 * bit. Repeating this process in a loop until x = 0 will count every
 * 1 bit in x.
 *
 * 1. 0111 & 0110 = 0110
 * 2. 0110 & 0101 = 0100
 * 3. 0100 & 0011 = 0000
 */

#include <stdio.h>

int bitcount(unsigned x);
int fastbitcount(unsigned x);

int main() {

    unsigned x = 238;

    printf("%d\n", bitcount(x));
    printf("%d\n", fastbitcount(x));
    
    return 0;
}

/* fastbitcount: count 1 bits in x faster */
int fastbitcount(unsigned x) {

    int b = 0;
    while (x != 0) {
	x &= (x-1);
	b++;
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
