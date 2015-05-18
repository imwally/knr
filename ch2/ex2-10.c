/* Exercise 2-10
 *
 * Rewrite the function lower, which converts upper case letters to
 * lower case, with a condition expression instead of if-else.
 */

#include <stdio.h>

void lower(char s[]);

int main() {

    char str[10] = "HeLLo";

    printf("str before lower: %s\n", str);

    lower(str);
    printf("str after lower: %s\n", str);

    return 0;
}

void lower(char s[]) {

    int i;
    for (i = 0; s[i] != '\0'; i++) {
	s[i] = (s[i] >= 'A' && s[i] <= 'Z') ? s[i] + 'a' - 'A' : s[i];
    }
}
