/* Exercise 4-14
 *
 * Define a macro swap(t,x,y) that interchanges two arguments of type
 * t. (Block structures will help.)
 */

#include <stdio.h>

#define swap(T,X,Y)				\
    {						\
	T Z = X;				\
	X = Y;					\
	Y = Z;					\
    }

int main() {

    int a = 1;
    int b = 2;

    swap(int, a, b);
    printf("a: %d\tb: %d\n", a, b);
}
