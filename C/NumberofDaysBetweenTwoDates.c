#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int dayToZero(int day, int month, int year)  //days to 0000-00-00 Fri
{
	int mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	for (int i = 1; i < month; ++i)
		day += mon[i];
	if (isLeapYear(year) && month > 2)
		++day;
	for (int i = 1; i < year; ++i)
		day += 365 + (isLeapYear(i) ? 1 : 0);
	return day;
}

int daysBetweenDates(char* date1, char* date2)
{
	int year1, month1, day1;
	int year2, month2, day2;
	sscanf(date1, "%d-%d-%d", &year1, &month1, &day1);
	sscanf(date2, "%d-%d-%d", &year2, &month2, &day2);
	return abs(dayToZero(day1, month1, year1) - dayToZero(day2, month2, year2));
}
