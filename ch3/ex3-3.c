/* Exercise 3-3
 *
 * Write a function expand(s1,s2) that expands shorthand notations
 * like a-z in the s1 into the equivalent complete list abc...xyz in
 * s2. Also for letters of either case and digits, and be prepared to
 * handle cases like a-b-c and a-z0-9 and -a-z. Arrange that a leading
 * or trailing - is taken literally.
 */

#include <stdio.h>
#include <ctype.h>

#define MAX 1000

void expand(char s1[], char s2[]);


int main() {

    char msg1[MAX] = "I'd like to expand a-h, L-Q, and maybe r-v-z ... oh and 0-9.\n";
    char msg2[MAX];
    
    printf("unexpanded:\n%s\n", msg1);

    expand(msg1, msg2);
    printf("expanded:\n%s\n", msg2);

    return 0;
}

void expand(char s1[], char s2[]){

    int i, j;
    for (i = j = 0; s1[i] != '\0'; ++i, ++j) {

	/* expand only if a character precedes the dash */
	if (s1[i] == '-' && s1[i-1] != ' ') {

	    for (s2[j] = s1[i-1]+1; s2[j] != s1[i+1]; ++j) {
		s2[j+1] = s2[j]+1;
	    }

	    /* jump foward to make up for the character after the
	     * dash */
	    ++i;
	}

	/* otherwise copy over regular characteres from s1 */
	s2[j] = s1[i];
    }

    /* terminate s2 */
    s2[j] = '\0';

}
