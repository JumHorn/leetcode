#include <vector>
using namespace std;

class Solution
{
public:
	int numberOfSets(int n, int k)
	{
		vector<vector<int>> dp(n + 1, vector<int>(k));
		for (int i = 0; i < n; ++i)
			dp[i + 1][0] = i * (i + 1) / 2;
		for (int j = 1; j < k; ++j)
		{
			int sum = 0;
			for (int i = 0; i < n; ++i)
			{
				// for (int l = 0; l <= i; ++l)
				// 	dp[i + 1][j] = (dp[i + 1][j] + dp[l][j - 1]) % MOD;
				sum = (sum + dp[i][j - 1]) % MOD;
				dp[i + 1][j] = (dp[i + 1][j] + sum) % MOD;
				dp[i + 1][j] = (dp[i + 1][j] + dp[i][j]) % MOD;
			}
		}
		return dp[n][k - 1];
	}

private:
	static const int MOD = 1e9 + 7;
};