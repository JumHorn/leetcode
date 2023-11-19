#include <string>
using namespace std;

class Solution
{
public:
	long long minimumSteps(string s)
	{
		long long N = s.size(), ones = s[0] - '0', dp = 0;
		for (int i = 1; i < N; ++i)
		{
			if (s[i] == '0')
				dp += ones;
			else
				++ones;
		}
		return dp;
	}
};