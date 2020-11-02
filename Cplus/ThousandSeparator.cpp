#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
	string thousandSeparator(int n)
	{
		if (n == 0)
			return "0";
		string res;
		int count = 0;
		while (n != 0)
		{
			res.push_back(n % 10 + '0');
			n /= 10;
			if (++count == 3 && n != 0)
			{
				count = 0;
				res.push_back('.');
			}
		}
		reverse(res.begin(), res.end());
		return res;
	}
};