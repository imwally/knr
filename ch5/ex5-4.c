/* Exercise 5-4
 *
 * Write the function strend(s,t), which returns 1 if the string t
 * occurs at the end of the string s, and zero otherwise.
 */

#include <stdio.h>
#include <string.h>

int strend(char *s, char *t);

int main(void) {

    char a[] = "hello, world";
    char b[] = "worlf";
    char c[] = "world";
    char d[] = "ing";
    char e[] = "testing";

    printf("%s\t%s = %d\n", a, b, strend(a, b));
    printf("%s\t%s = %d\n", a, c, strend(a, c));
    printf("%s\t%s = %d\n", c, d, strend(c, d));
    printf("%s\t%s = %d\n", e, d, strend(e, d));
    
}

int strend(char *s, char *t) {

    /* get difference of s - t */
    int diff = strlen(s) - strlen(t);

    /* new pointer that points to s + that difference */
    char *s_diff;
    s_diff = s+diff;

    /* check equality of each character */
    for(; *s_diff == *t; s_diff++, t++) {
	/* all characters were equal up til end of s */
	if (*s_diff == '\0') {
	    return 1;
	}
    }

    /* strings were different */
    return 0;
}
