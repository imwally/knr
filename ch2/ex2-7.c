/* Exercise 2-7
 *
 * Write a function invert(x,p,n) that returns x with the n bits that
 * begin at position p inverted (i.e., 1 changed into 0 and vice
 * versa), leaving the others unchaged.
 */

#include <stdio.h>

unsigned invert(unsigned x, int p, int n);
unsigned getbits(unsigned x, int p, int n);

int main() {

    int x = 0xb5; /* 10110101 (181) */

    /* invert(x, 3, 3):
     *
     * x = 1  0  1  1  0  1  0  1
     *     7  6  5  4  3  2  1  0
     *                 ^-----^
     *
     * The 3 bits that begin at position 3 must be inverted.
     *
     * x = 1  0  1  1  1  0  1  1 
     *                 ^-----^
     *
     * This is 187 in decimal.
     */

    printf("x: %d\n", x);
    printf("invert(x, 3, 3): %d\n", invert(x, 3, 3));

    /* invert(x, 4, 2):
     *
     * x = 1  0  1  1  0  1  0  1
     *     7  6  5  4  3  2  1  0
     *              ^--^
     *
     * The 3 bits that begin at position 3 must be inverted.
     *
     * x = 1  0  1  0  1  1  0  1 
     *              ^--^
     *
     * This is 173 in decimal.
     */

    printf("invert(x, 4, 2): %d\n", invert(x, 4, 2));
}

unsigned invert(unsigned x, int p, int n) {

    /* get inverted n bits of x starting at position p 
     * and move bits back to position p    
     */
    unsigned y = getbits(~x,p,n) << (p+1-n);
    
    /* zero out n bits starting at position p of x */
    x = x & ~((~(~0 << n)) << (p+1-n));
    
    return y | x;
}

unsigned getbits(unsigned x, int p, int n) {
    return (x >> (p+1-n)) & ~(~0 << n);
}
