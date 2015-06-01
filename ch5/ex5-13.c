/* Exercise 5-13
 *
 * Write the program tail, which prints the last n lines of its
 * input. By default, n is set to 10, let us say, but it can be
 * changed by an optional argument so that
 *
 * tail -n
 * 
 * prints the last n lines.
 */

#include <stdio.h>
#include <stdlib.h>

main(int argc, char *argv[]) {

    int c, lines;
    lines = 10;

    while (--argc > 0 && (*++argv)[0] == '-') {
	while (c = *++argv[0]) {
	    switch (c) {
	    case 'n':
		lines = atoi(*++argv);
		argc = 0;
		break;
	    default:
		argc = 0;
		break;
	    }
	}
    }

    printf("%d\n", lines);
    
}
