#include <vector>
using namespace std;

class Solution
{
public:
	int countSpecialSubsequences(vector<int> &nums)
	{
		int N = nums.size();
		vector<vector<long>> dp(N + 1, vector<long>(3));
		for (int i = 0; i < N; ++i)
		{
			if (nums[i] == 0)
				dp[i + 1][0] = (dp[i][0] * 2 + 1) % MOD;
			else
				dp[i + 1][0] = dp[i][0];
		}
		for (int k = 1; k <= 2; ++k)
		{
			for (int i = 0; i < N; ++i)
			{
				if (nums[i] == k)
					dp[i + 1][k] = (dp[i][k] * 2 + dp[i][k - 1]) % MOD;
				else
					dp[i + 1][k] = dp[i][k];
			}
		}
		return dp[N][2];
	}

private:
	static const int MOD = 1e9 + 7;
};