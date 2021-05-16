#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int rearrangeSticks(int n, int k)
	{
		// place the sticker from largest to smallest
		vector<vector<int>> dp(n, vector<int>(k));
		dp[0][0] = 1;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < k && j <= i; ++j)
			{
				if (i >= 1 && j >= 1)
					dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
				if (i >= 1)
					dp[i][j] = (dp[i][j] + long(i) * dp[i - 1][j]) % MOD;
			}
		}
		return dp[n - 1][k - 1];
	}

private:
	static const int MOD = 1e9 + 7;
};