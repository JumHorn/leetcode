#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int largestVariance(string s)
	{
		int res = 0, N = s.length();
		for (char i = 'a'; i <= 'z'; ++i)
		{
			for (char j = 'a'; j <= 'z'; ++j)
			{
				if (i != j)
					res = max(res, variance(s, i, j));
			}
		}
		return res;
	}

	int variance(string s, char a, char b)
	{
		int res = 0, var = 0;
		bool has_b = false, first_b = false;
		for (auto c : s)
		{
			if (c == a)
				++var;
			else if (c == b)
			{
				has_b = true;
				if (first_b && var >= 0)
					first_b = false;
				else if (--var < 0)
				{
					first_b = true;
					var = -1;
				}
			}
			res = max(res, has_b ? var : 0);
		}
		return res;
	}
};