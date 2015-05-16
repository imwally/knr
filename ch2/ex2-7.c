/* Exercise 2-7
 *
 * Write a function invert(x,p,n) that returns x with the n bits that
 * begin at position p inverted (i.e., 1 changed into 0 and vice
 * versa), leaving the others unchaged.
 */

#include <stdio.h>

unsigned invert(unsigned x, int p, int n);

int main() {

    int x = 0xb5; /* 10110101 (181) */

    /* invert(x, 3, 3):
     *
     * x = 1  0  1  1  0  1  0  1
     *     7  6  5  4  3  2  1  0
     *           ^-----^
     *
     * The 3 bits that begin at position 3 must be inverted.
     *
     * x = 1  0  0  0  1  1  0  1
     *           ^-----^
     *
     * This is 141 in decimal.
     */

    printf("x inverted: %d\n", invert(x, 3, 3));
}

unsigned invert(unsigned x, int p, int n) {

}
