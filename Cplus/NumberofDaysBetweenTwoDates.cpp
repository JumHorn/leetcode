#include <cmath>
#include <sstream>
#include <string>
using namespace std;

class Solution
{
public:
	int daysBetweenDates(string date1, string date2)
	{
		int year1, month1, day1;
		int year2, month2, day2;
		char dash = ' ';
		stringstream ss1(date1), ss2(date2);
		ss1 >> year1 >> dash >> month1 >> dash >> day1;
		ss2 >> year2 >> dash >> month2 >> dash >> day2;
		return abs(dayToZero(day1, month1, year1) - dayToZero(day2, month2, year2));
	}

	int dayToZero(int day, int month, int year) //days to 0000-00-00 Fri
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

	bool isLeapYear(int year)
	{
		return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	}
};