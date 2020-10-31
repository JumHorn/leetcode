#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	string dayOfTheWeek(int day, int month, int year)
	{
		vector<string> week = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
		int diff = dayToZero(day, month, year);
		return week[diff % 7];
	}

	bool isLeapYear(int year)
	{
		return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
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
};