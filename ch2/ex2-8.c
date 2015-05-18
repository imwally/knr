/* Exercise 2-8
 * 
 * Write a function rightrot(x,n) that returns the value of the
 * integer x rotated to the right by n positions.
 */

#include <stdio.h>

unsigned rightrot(unsigned x, int n);

int main() {

    int x = 0x9a; /* 10011010 (154) */

    /* rotated right by 1: 01001101 (77)
     * rotated right by 2: 10100110 (166)
     * rotated right by 3: 01010011 (83)
     * rotated right by 4: 10101001 (169)
     * rotated right by 5: 11010100 (212)
     * rotated right by 6: 01101010 (106)
     * rotated right by 7: 00110101 (53)
     * rotated right by 8: 10011010 (154)
     */

    printf("%d\n", rightrot(x, 5));
    
    return 0;
}

unsigned rightrot(unsigned x, int n) {

    /* get n bits that fall off the right, shift them 8-n places to
     * the left, then OR with x shifted n places to the right
     */
    return (~(~0 << n) & x) << (8-n) | (x >> n);
    
}
