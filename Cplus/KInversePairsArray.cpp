#include <vector>
using namespace std;

/*
dp(i, j) = dp(i - 1, j) + dp(i - 1, j - 1) + ... + dp(i - 1, j - i + 1)
dp(i, j - 1) = dp(i - 1, j - 1) + dp(i - 1, j - 2) + ... + dp(i - 1, j - i)

dp(i, j) - dp(i - 1, j) = dp(i, j - 1) - dp(i - 1, j - i) ==>
dp(i, j) = dp(i, j - 1) + dp(i - 1, j) - dp(i - 1, j - i)
*/

class Solution
{
public:
	int kInversePairs(int n, int k)
	{
		vector<vector<int>> dp(n + 1, vector<int>(k + 1));
		for (int i = 1; i <= n; ++i)
			dp[i][0] = 1;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= min(k, i * (i - 1) / 2); ++j)
			{
				long val = (j >= i ? dp[i - 1][j - i] : 0);
				dp[i][j] = (dp[i][j - 1] + dp[i - 1][j] - val + MOD) % MOD;
			}
		}
		return dp[n][k];
	}

private:
	static const int MOD = 1e9 + 7;
};