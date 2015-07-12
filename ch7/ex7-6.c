/* Exercise 7-6
 *
 * Write a program to compare two files, printing the first line where they
 * differ.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

void *fcompare(FILE *fp1, FILE *fp2)
{
    char line1[MAXLINE];
    char line2[MAXLINE];
    char *status1, *status2;

    int compare, lnum1, lnum2;
    lnum1 = lnum2 = 0; 
    compare = 0; 

    while (compare == 0) {
        status1 = fgets(line1, MAXLINE, fp1);
        status2 = fgets(line2, MAXLINE, fp2);
    
        if (status1 == NULL && status2 == NULL) {
            break;
        }

        if (status1 != NULL) {
            ++lnum1;
        }

        if (status2 != NULL) {
            ++lnum2;
        }

        if ((compare = strcmp(line1, line2)) != 0) {
            fprintf(stderr, "%d: %s", lnum1, line1);
            fprintf(stderr, "%d: %s", lnum2, line2);
        } 
        
        
    }
  
}


main(int argc, char *argv[])
{
    /* file pointers */
    FILE *fp1, *fp2;

    /* program name */
    char *prog = argv[0];

    /* check argument length */
    if (argc != 3) {
        fprintf(stderr, "%s: need two files to compare\n", prog);
        exit(1);
    }

    /* open files */
    if ((fp1 = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "%s: can't open %s\n", prog, argv[1]);
        exit(2);
    }

    if ((fp2 = fopen(argv[2], "r")) == NULL) {
        fprintf(stderr, "%s: can't open %s\n", prog, argv[2]);
        exit(2);
    }

    /* compare files */
    fcompare(fp1, fp2);

    /* close files */
    fclose(fp1);
    fclose(fp2);

    /* in case stdout can be written to */
    if (ferror(stdout)) {
        fprintf(stderr, "%s: error writing stdout \n", prog);
        exit(3);
    }

    exit(0);
}

