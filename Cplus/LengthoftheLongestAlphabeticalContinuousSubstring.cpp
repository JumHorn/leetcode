#include <string>
using namespace std;

class Solution
{
public:
	int longestContinuousSubstring(string s)
	{
		int res = 1, N = s.size();
		for (int i = 1, j = 0; i <= N; ++i)
		{
			if (i == N || s[i] - s[i - 1] != 1)
			{
				res = max(res, i - j);
				j = i;
			}
		}
		return res;
	}
};