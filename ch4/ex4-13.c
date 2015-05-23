/* Exercise 4-13
 *
 * Write a recursive version of the function reverse(s), which
 * reverses the string s in place.
 */

#include <stdio.h>
#include <string.h>

int main() {

    void reverse(char s[]);
    char s[] = "reverse this string";

    reverse(s);
    printf("%s\n", s);
}

void reverse(char s[]) {

    /* hold variables on each invocation */
    static int i, c, d;

    /* get string length on first invocation */
    if (i < 1) {
	d = strlen(s)-1;
    }

    /* swap characters */
    c = s[i];
    if (i < d) {
	s[i] = s[d];
	s[d] = c;
	++i;
	--d;
	reverse(s);
    }

}
