#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int maxCoins(vector<int> &nums)
	{
		nums.insert(nums.begin(), 1);
		nums.push_back(1);
		int n = nums.size();
		vector<vector<int>> dp(n, vector<int>(n));
		for (int len = 2; len < n; len++)
		{
			for (int i = 0; i < n - len; i++)
			{
				int j = i + len;
				for (int k = i + 1; k < j; k++)
					dp[i][j] = max(dp[i][j], nums[i] * nums[k] * nums[j] + dp[i][k] + dp[k][j]);
			}
		}
		return dp[0][n - 1];
	}
};