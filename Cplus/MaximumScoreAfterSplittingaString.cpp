#include <string>
using namespace std;

class Solution
{
public:
	int maxScore(string s)
	{
		int res = 0, zero = 0, one = 0;
		for (auto c : s)
			c == '0' ? ++zero : ++one;
		int left = 0, right = one;
		for (int i = 0; i < (int)s.length() - 1; ++i)
		{
			s[i] == '0' ? ++left : --right;
			res = max(res, left + right);
		}
		return res;
	}
};
