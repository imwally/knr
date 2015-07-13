/* Rewrite the program cat from Chapter 7 using read, write, open, and close
 * instead of their standard library equivalents. Perform experiments to
 * determine the relative speeds of the two versions.
 */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

main(int argc, char *argv[])
{
    int f1, n;
    char buf[BUFSIZ];

    if (argc != 2) {
        fprintf(stderr, "cat: need one argument\n");
    }
    
    else {

        if ((f1 = open(argv[1], O_RDONLY, 0)) == -1) {
            fprintf(stderr, "cat: can't open %s\n", argv[1]);
        }

        while ((n = read(f1, buf, BUFSIZ)) > 0) {
            if (write(1, buf, n) != n) {
                error("cat: write error to stdout");
            }
        }
    }

    close(f1);
    return 0;
} 
