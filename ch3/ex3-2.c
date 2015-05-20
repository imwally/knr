/* Exercise 3-2
 *
 * Write a fucniton escape(s,t) that converts characters like newline
 * and tab into visible escape sequences like \n and \t as it copies
 * the string t to s. Use a switch. Write a function for the other
 * direction as well, converting escape sequences into the real
 * characters.
 */

#include <stdio.h>

#define MAX 1000

void escape(char s[], char t[]);

int main() {

    char msg[MAX] = "This is my\nmessage that\nhas new lines\tand\tsome tabs in it.";
    char escaped[MAX];

    escape(msg, escaped);
    printf("message:\n%s\n\n", msg);
    printf("escaped:\n%s\n", escaped);

}

void escape(char s[], char t[]) {

    int i, j;

    for(i = j =0; s[i] != '\0'; ++i) {
	
	switch(s[i]) {
	case '\t':
	    t[j++] = '\\';
	    t[j++] = 't';
	    break;
	case '\n':
	    t[j++] = '\\';
	    t[j++] = 'n';
	    break;
	default:
	    t[j++] = s[i];
	    break;
	}
    }

    t[j] = '\0';
}
