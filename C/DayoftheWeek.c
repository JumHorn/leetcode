#include <stdbool.h>

bool isLeapYear(int year)
{
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int dayToZero(int day, int month, int year) //days to 0000-00-00 Fri
{
	int mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	for (int i = 1; i <= 12; ++i)
		mon[i] += mon[i - 1];
	if (isLeapYear(year) && month > 2)
		++day;
	day += mon[month - 1];
	--year;
	day += year * 365;
	day += year / 4 - year / 100 + year / 400;
	return day;
}

char *dayOfTheWeek(int day, int month, int year)
{
	char *week[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	int diff = dayToZero(day, month, year);
	return week[diff % 7];
}