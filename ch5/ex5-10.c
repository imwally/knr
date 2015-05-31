/* Exercise 5-10
 *
 * Write the program expr, which evaluates a reverse Polish expression
 * from the comand line, where ear operator or operand is a separate
 * argument. For example,
 *
 * expr 2 3 4 + *
 *
 * evaluates 2 * (3+4).
 */

#include <stdio.h>
#include <stdlib.h>

main(int argc, char *argv[]) {

    int sum;
    
    if (*argv[argc-1] != '+') {
	printf("Usage: expr 1 2 +\n");
    }

    else {

	/* skip command name */
	*argv++;
	
	while (--argc-1 > 0) {
	    sum += atoi(*argv++);
	}

	printf("%d\n", sum);
    }
	

}

