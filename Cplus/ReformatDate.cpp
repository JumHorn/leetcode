#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	string reformatDate(string date)
	{
		vector<string> Month = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
		unordered_map<string, int> month;
		for (int i = 0; i < (int)Month.size(); ++i)
			month[Month[i]] = i + 1;

		stringstream ss(date), res;
		string year, mon, day;
		ss >> day >> mon >> year;
		res << year << '-';
		int m = month[mon];
		if (m < 10)
			res << '0';
		res << m << '-';
		if (day[1] >= '0' && day[1] <= '9')
			res << day[0] << day[1];
		else
			res << '0' << day[0];
		return res.str();
	}
};