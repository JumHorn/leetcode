#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxSumDivThree(vector<int> &nums)
	{
		vector<int> dp = {0, 0, 0}, pre_dp;
		for (auto n : nums)
		{
			pre_dp = dp;
			for (auto sum : pre_dp)
				dp[(sum + n) % 3] = max(dp[(sum + n) % 3], sum + n);
		}
		return dp[0];
	}
};