#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

class Solution
{
public:
	string convertToBase7(int num)
	{
		stringstream ss;
		if (num == 0)
			return "0";
		int sign = 1;
		if (num < 0)
		{
			num = -num;
			sign = -1;
		}
		while (num != 0)
		{
			ss << num % 7;
			num /= 7;
		}
		if (sign == -1)
			ss << "-";
		string res = ss.str();
		reverse(res.begin(), res.end());
		return res;
	}
};