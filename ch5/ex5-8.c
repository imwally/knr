/* Exercise 5-8
 *
 * There is no error checking in day_of_year or month_day. Remedy this
 * defect.
 */

#include <stdio.h>

int day_of_year(int year, int month, int day);
void month_day(int year, int yearday, int *pmonth, int *pday);

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int main(void) {

    int m, d;

    /* day_of_year */
    printf("day_of_year(2015, 5, 29): %d\n", day_of_year(2015, 5, 29));
    printf("day_of_year(2015, 14, 29): %d\n", day_of_year(2015, 14,29));
    printf("day_of_year(2015, 5, 32): %d\n", day_of_year(2015, 5, 32));

    /* month_day */
    month_day(2015, 366, &m, &d);
    printf("month_day(2015, 366, &m, &d): m: %d d: %d\n", m, d);    

    month_day(2016, 366, &m, &d);
    printf("month_day(2016, 366, &m, &d): m: %d d: %d\n", m, d);    
    
    month_day(2015, 149, &m, &d);
    printf("month_day(2015, 149, &m, &d): m: %d d: %d\n", m, d);
}

/* day_of_year: set day of year from month & day */
int day_of_year(int year, int month, int day) {

    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    /* make sure months are 1-12 and days are 1-31 */
    if (month > 0 && month <= 12 && day > 0 && day <= 31) {
    
	for (i = 1; i < month; i++) {
	    day += daytab[leap][i];
	}
	
	return day;
    }

    else {
	return -1;
    }
}

/* month_day: set month, day from day of year */
void month_day(int year, int yearday, int *pmonth, int *pday) {

    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    /* make sure yearday is 1-365 or 1-366 for leap years */
    if (yearday > 0 && yearday <= 365 || leap > 0 && yearday > 0 && yearday <=366) {
	for (i = 1; yearday > daytab[leap][i]; i++) {
	    yearday -= daytab[leap][i];
	}
	*pmonth = i;
	*pday = yearday;
    }

    else {
	*pmonth = -1;
	*pday = -1;
    }
}
