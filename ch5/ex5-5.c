/* Exercise 5-5
 *
 * Write versions of the library functions strncpy, strncat, and
 * strncmp, which operate on at most the first n characters of their
 * argument strings. For example, strncpy(s,t,n) copies at most n
 * characters of t to s.
 */

#include <stdio.h>

void mystrncpy(char *s, char *t, int n);
void mystrncat(char *s, char *t, int n);
int mystrncmp(char *s, char *t, int n);
    
int main(void) {

    /* mystrncpy */
    char a[20] = "this is only a test.";
    char b[20] = "";
    
    printf("a: %s\n", a);
    printf("b: %s\n", b);

    mystrncpy(b,a,10);
    printf("b after mystrncpy(b, a, 10): %s\n\n", b);

    printf("---\n");
    
    /* mystrncat */
    char c[20] = "hello, ";
    char d[20] = "world!";

    printf("c: %s\n", c);
    printf("d: %s\n", d);

    mystrncat(c, d, 4);
    printf("c after mystrncat(c, d, 4): %s\n\n", c);

    printf("---\n");
    
    /* mystrcmp */
    char e[20] = "coffee and cream";
    char f[20] = "coffee and sugar";


    printf("e: %s\n", e);
    printf("f: %s\n", f);
    
    mystrncmp(f, e, 5);
    printf("mystrncmp(f, e, 10): %d\n", mystrncmp(f, e, 10));
    printf("mystrncmp(f, e, 11): %d\n", mystrncmp(f, e, 11));
    
}

/* strncpy: copies up to first n characters of t to s */
void mystrncpy(char *s, char *t, int n) {

    int i;
    for (i = 0; i < n; ++i) {
	*s++ = *t++;
    }
}

/* strncat: concatenate first n characters of t to the end of s */
void mystrncat(char *s, char *t, int n) {

    /* find end of s */
    while (*s != '\0') {
	s++;
    }

    int i;
    for (i = 0; i < n; ++i) {
	*s++ = *t++;
    }
}

/* strncmp: compare the first n characters of t to s */
int mystrncmp(char *s, char *t, int n) {

    int i;
    for(i = 0; *s == *t; i++, s++, t++) {
	if (i == n) {
	    return 0;
	}
    }

    return *s - *t;
	
}
