/* Exercise 2-6 
 * 
 * Write a function setbits(x,p,n,y) that returns x with the n bits that begin
 * at position p set to the rightmost n bits of y, leaving the other bits
 * unchanged.
 */

#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main() {

    unsigned int x = 0x4a;   /* 01001010 (74) */
    unsigned int y = 0x3c;   /* 00111100 (60) */

    printf("x: %x\n", x);
    printf("y: %x\n", y);
    
    /* setbits(x, 4, 4, y):
     *
     * x = 0  1  0  0  1  0  1  0
     *     7  6  5  4  3  2  1  0
     *     ^--------^
     *
     * The 4 bits that begin at position 4 must be set to the rightmost 4 bits
     * of y.
     *
     * y = 0  0  1  1  1  1  0  0
     *                 ^--------^
     *
     * These 4 bits should replace the 4 in x.
     *
     * x = 1  1  0  0  1  0  1  0
     *
     * In decimal this is 202.
     */

    printf("setbits(x, 4, 4, y) = %d\n", setbits(x, 4, 4, y));

}

unsigned setbits(unsigned x, int p, int n, unsigned y) {

    /* clear all but right most n bits of y */
    y = ~(~0 << n) & y;

    /* shift bits in y to position p */
    y = y << p;

    /* inclusive or x an y */
    return y | x;
}
