/* Exercise 2-2
 *
 * for (i = 0; i < lim-1 && (c = getchar()) != '\n' && c != EOF; ++i)
 *    s[i] = c;
 *
 * Write a loop equivalent to the for loop above without using && or ||.
 */

#include <stdio.h>

main() {

    int i, c;
    int lim = 500;

    char s[lim];
    
    while ((c = getchar()) != EOF) {
	if (i < lim-1) {
	    if (c != '\n') {
		s[i] = c;
		++i;
	    }
	}
    }

    printf("%s\n", s);

    return 0;
}
