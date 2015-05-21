/* Exercise 4-1
 *
 * Write the function strindex(s,t) which returns the position of the
 * rightmost occurence of t in s, or -1 if there is none.
 */

#include <stdio.h>

int strindex(char s[], char t[]);

int main() {

    char str[100] = "Hello, world! Print this string!";
    char find[100] = "i";
    
    printf("%d\n", strindex(str, find));
	
}

/* strindex: return rightmost index of t in s, -1 if none */
int strindex(char s[], char t[]) {

    int i, j, k, l;

    l = 0;
    for (i = 0; s[i] != '\0'; i++) {
	for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++) {
	    ;
	}
	if (k > 0 && t[k] == '\0') {
	    l = i;
	}
    }

    if (l > 0) {
	return l;
    }

    return -1;
}
