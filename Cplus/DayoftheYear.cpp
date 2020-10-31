#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int dayOfYear(string date)
	{
		vector<int> mon = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		char dash = ' ';
		int day, month, year;
		stringstream ss(date);
		ss >> year >> dash >> month >> dash >> day;
		for (int i = 1; i < month; ++i)
			day += mon[i];
		if (isLeapYear(year) && month > 2)
			++day;
		return day;
	}

	bool isLeapYear(int year)
	{
		return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	}
};