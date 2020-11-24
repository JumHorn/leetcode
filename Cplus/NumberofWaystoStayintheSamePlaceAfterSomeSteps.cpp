#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int numWays(int steps, int arrLen)
	{
		int N = min(steps, arrLen);
		vector<int> dp(N + 2);
		dp[1] = dp[2] = 1;
		for (int i = 1; i < steps; ++i)
		{
			vector<int> dp_copy(dp);
			for (int j = 1; j <= min(i + 1, N); ++j)
			{
				dp[j - 1] = (dp[j - 1] + dp_copy[j]) % MOD;
				dp[j + 1] = (dp[j + 1] + dp_copy[j]) % MOD;
			}
		}
		return dp[1];
	}

private:
	static const int MOD = 1e9 + 7;
};