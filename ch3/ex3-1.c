/* Exercise 3-1
 *
 * Our binary search makes two tests inside the loop, when one would
 * suffice (at the price of more tests outside.) Write a version with
 * only one test inside the loop and measure the difference in
 * run-time.
 */

#include <stdio.h>

#define MAX 1000

int main() {

    int i, v[MAX];

    /* initilize array */
    for(i = 0; i <= MAX; i++) {
	v[i] = i;
    }

    int x = 823;
    int y = binsearch2(x, v, MAX);

    printf("searching for %d in the range of 0-%d...\n", x, MAX);
    
    if (y > 0) {
	printf("found %d\n", x);
    }
    else {
	printf("%d not found\n", x);
    }
    
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n) {

    int low, high, mid;

    low = 0;
    high = n - 1;

    while (low <= high) {

	/* set mid point by dividing search space in half */
	mid = (low + high)/2;

	/* if x is lower than mid point reduce the high to mid-1 */
	if (x < v[mid]) {
	    high = mid - 1;
	}

	/* if x is higher than mid point increase the low to mid+1 */
	else if (x > v[mid]) {
	    low = mid + 1;
	}

	/* if neither above return true then x == mid */
	else {
	    return mid;
	}
    }

    /* return -1 if low is not lower than or equal to high */
    return -1;
}
      
int binsearch2(int x, int v[], int n) {

    int low, high, mid;

    low = 0;
    high = n - 1;
    
    while (low < high) {

	mid = (low + high) / 2;

	if (x < v[mid]) {
	    high = mid - 1;
	}

	/* the else if in binsearch can be removed as it's safe to
	 * assume that x will be larger than mid if the above
	 * condition fails
	 */
	else {
	    low = mid + 1;
	}

    }

    /* when low > high the loop ends so x must equal v[low], otherwise
     * if it doesn't equal v[low] the loop never starts and returns -1
     */
    return (x == v[low]) ? low : -1;
}
