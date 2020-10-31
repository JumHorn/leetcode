#include <string>
using namespace std;

class Solution
{
public:
	int balancedStringSplit(string s)
	{
		int res = 0, count = 0;
		for (auto c : s)
		{
			c == 'L' ? ++count : --count;
			if (count == 0)
				++res;
		}
		return res;
	}
};