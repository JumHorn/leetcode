#include <stdbool.h>
#include <stdio.h>

bool isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int dayOfYear(char *date)
{
	int mon[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int day, month, year;
	sscanf(date, "%d-%d-%d", &year, &month, &day);
	for (int i = 1; i < month; ++i)
		day += mon[i];
	if (isLeapYear(year) && month > 2)
		++day;
	return day;
}