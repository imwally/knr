#include <stdio.h>

/* Exercise 1-2
 *
 * Experiment to find out what happens when prints's arugment string
 * contains \c, where c is some character not listed above.
 */

main() {
    printf("hello, \c world\n");
    /* compiler output:
     * ex1-2.c:10:20: warning: unknown escape sequence '\c'
     */
}
