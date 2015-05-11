/* Exercise 2-3
 *
 * Write a function htoi(s), which converts a string of hexidecimal
 * digits (including an optional 0x or 0X) into its equivalent integer
 * value. The allowable digits are 0 through 9, a through f, and A
 * through F.
 */

#include <stdio.h>
#include <ctype.h>

long htoi(char s[]);

void main() {

    char hexstring[20] = "0xdeadBEEF";

    printf("%lu\n", htoi(hexstring));
    
}

long htoi(char s[]) {

    long n, i , j;

    n = 0;
    i = 0;
    j = 0;

    int length = len(s) - 1;
    
    while (s[i] != '\0') {

	if (!isdigit(s[i])) {
	    if (s[i] >= 'A' && s[i] <= 'F' || s[i] >= 'a' && s[i] <= 'f') {
		j = tolower(s[i]);
		j = (j - 'a') + 10;
		n = n + (j * power(16, (length - i)));
	    }
	}

	else {
	    j = s[i] - '0';
	    n = n + (j * power(16, (length - i)));
	}
	
	++i;
    }

    return n;
}
	
	
int power(int base, int n) {
    int i, p;

    p = 1;
    for (i = 1; i <= n; ++i) {
	p = p * base;
    }

    return p;
}

int len(char s[]) {

    int i = 0;
    while (s[i] != '\0') {
	++i;
    }

    return i;
}
