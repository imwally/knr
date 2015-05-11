/* Exercise 2-4
 *
 * Write an alternative version of squeeze(s1, s2) that deletes each
 * character in s1 that matches any character in string s2.
 */

#include <stdio.h>

void squeeze(char s[], int c);
void squeezestr(char s1[], char s2[]);

int main() {

    char s1[10] = "abcdef";
    char s2[10] = "dae";

    squeezestr(s1, s2);

    printf("%s\n", s1);
}



/* squeezestr: delete each character in s1 that matches any character
 * in s2 
 */
void squeezestr(char s1[], char s2[]) {
    int i, j, k;

    
    /* loop over each character in s2 */
    for (i = 0; s2[i] != '\0'; ++i) {

	/* on each character of s2 loop over each character of s1 */
	for (j = k = 0; s1[j] != '\0'; ++j) {

	    /* if there is no match add character to s1 */
	    if (s1[j] != s2[i]) {
		s1[k++] = s1[j];
	    }
	}

	/* reset s1 to new string: each loop will decrease string
	 * length
	 */
	s1[k] = '\0';
    }
}



/* squeeze: delete all c from s */
void squeeze(char s[], int c) {
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++) {
	if (s[i] != c) {
	    s[j++] = s[i];
	}
    }

    s[j] = '\0';
}
