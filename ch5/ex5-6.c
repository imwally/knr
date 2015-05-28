/* Exercise 5-6
 *
 * Rewrite appropriate programs from earlier chapters and exercises
 * with pointers instead of array indexing.
 *
 * Rewriting getline().
 */

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line length */

int getline(char *, int lim);

int main(void) {

    int len;
    char line[MAXLINE];
    
    while ((len = getline(line, MAXLINE)) > 0) {
	printf("%s\n", line);
    }

    return 0;

}

/* getline: read a line into s, return length */
int getline(char *s, int lim) {

    int c, i;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i) {
	*s++ = c;
    }

    if (c == '\n') {
	*s = c;
	++i;
    }

    *s++ = '\0';

    return i;
}
