#include <string>
using namespace std;

class Solution
{
public:
	int maxPower(string s)
	{
		int res = 1, count = 0;
		char pre = '\0';
		for (auto c : s)
		{
			if (pre == c)
				res = max(res, ++count);
			else
			{
				count = 1;
				pre = c;
			}
		}
		return res;
	}
};
