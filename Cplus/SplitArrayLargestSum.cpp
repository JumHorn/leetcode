#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int splitArray(vector<int> &nums, int m)
	{
		int n = nums.size();
		vector<long> prefix(n + 1);
		for (int i = 0; i < n; ++i)
			prefix[i + 1] += prefix[i] + nums[i];
		vector<vector<long>> dp(m + 1, vector<long>(n + 1));
		for (int i = 0; i < n; ++i)
			dp[1][i + 1] = prefix[i + 1];
		for (int i = 2; i <= m; ++i)
		{
			for (int j = i - 1; j <= n; j++)
			{
				dp[i][j] = INT_MAX;
				for (int k = j - 1; k >= i - 2; k--)
					dp[i][j] = min(dp[i][j], max(dp[i - 1][k], prefix[j] - prefix[k]));
			}
		}
		return dp[m][n];
	}
};