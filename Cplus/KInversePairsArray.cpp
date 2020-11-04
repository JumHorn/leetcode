#include <vector>
using namespace std;

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
			for (int j = 1; j <= k; ++j)
			{
				if (j >= i)
					dp[i][j] = (dp[i][j - 1] + (dp[i - 1][j] + MOD - dp[i - 1][j - i]) % MOD) % MOD;
				else
					dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % MOD;
			}
		}
		if (k > 0)
			return (dp[n][k] + MOD - dp[n][k - 1]) % MOD;
		return dp[n][k];
	}

private:
	static const int MOD = 1e9 + 7;
};