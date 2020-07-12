#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	string reformatDate(string date)
	{
		vector<string> v = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
		unordered_map<string, int> month;
		for (int i = 0; i < (int)v.size(); i++)
			month[v[i]] = i + 1;
		int n = date.length();
		string res = date.substr(n - 4) + "-";
		string mon = date.substr(n - 8, 3);
		int m = month[mon];
		if (m < 10)
			res += "0" + to_string(m);
		else
			res += to_string(m);
		res += "-";
		if (date[0] >= '0' && date[0] <= '9')
		{
			if (date[1] >= '0' && date[1] <= '9')
				res = res + date[0] + date[1];
			else
				res = res + "0" + date[0];
		}
		return res;
	}
};
