#include <string>
using namespace std;

class Solution
{
public:
	int daysBetweenDates(string date1, string date2)
	{
		int year1 = stoi(date1.substr(0, 4)), month1 = stoi(date1.substr(5, 2)), day1 = stoi(date1.substr(8, 2));
		int year2 = stoi(date2.substr(0, 4)), month2 = stoi(date2.substr(5, 2)), day2 = stoi(date2.substr(8, 2));
		return abs(dayDiff(1971, 1, 1, year1, month1, day1) - dayDiff(1971, 1, 1, year2, month2, day2));
	}

	int dayDiff(int year1, int month1, int day1, int year2, int month2, int day2)
	{
		int res = 0;
		for (int i = year1; i < year2; i++)
		{
			if (leapYear(i))
				res += 366;
			else
				res += 365;
		}
		int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		for (int i = 1; i < month2; i++)
			res += month[i];
		res += day2;
		if (month2 > 2 && leapYear(year2))
			res += 1;
		return res;
	}

	bool leapYear(int n)
	{
		if (n % 100 == 0)
			return n % 400 == 0;
		return n % 4 == 0;
	}
};
