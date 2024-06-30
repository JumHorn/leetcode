#include <vector>
using namespace std;

class Solution
{
public:
	int maximumLength(vector<int> &nums, int k)
	{
		vector<vector<int>> dp(k, vector<int>(k));
		int res = 0;
		for (auto n : nums)
		{
			for (int i = 0; i < k; ++i)
			{
				int r = n % k;
				dp[r][i] = dp[i][r] + 1;
				res = max(res, dp[r][i]);
			}
		}
		return res;
	}
};