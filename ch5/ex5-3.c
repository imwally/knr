/* Exercise 5-3
 *
 * Write a pointer version of the function strcat that we showed in
 * chapter 2: strcat(s,t) copies the string t to the end of s.
 */

#include <stdio.h>

void mystrcat(char *s, char *t);

int main(void) {

    char a[50] = "hello";
    char b[] = ", world! this is a test!";

    mystrcat(a, b);
    printf("%s\n", a);
}

void mystrcat(char *s, char *t) {

    /* increment pointer starting at *s until \0 is found */
    while (*s != '\0') {
	*s++;
    }

    /* append contents of t onto end of s */
    while (*s++ = *t++) {
	;
    }
    
}
