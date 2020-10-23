#include <numeric>
#include <vector>
using namespace std;

/*
for j = 0, 1, ..., faces - 1
dp[i][j] means how many combinations it could be that at i-th rolling and the last face is j
for j = faces
dp[i][j] means how many combinations it could be that at i-th rolling in total
*/

class Solution
{
public:
	int dieSimulator(int n, vector<int> &rollMax)
	{
		int faces = rollMax.size();
		vector<vector<long>> dp(n + 1, vector<long>(faces + 1));
		dp[0][faces] = 1;
		for (int i = 0; i < faces; ++i)
			dp[1][i] = 1;
		dp[1][faces] = faces;
		for (int i = 2; i <= n; ++i)
		{
			for (int j = 0; j < faces; ++j)
			{
				for (int k = 1; k <= rollMax[j] && i - k >= 0; ++k)
					dp[i][j] = (dp[i][j] + dp[i - k][faces] - dp[i - k][j] + MOD) % MOD;
				dp[i][faces] = (dp[i][faces] + dp[i][j]) % MOD;
			}
		}
		return dp[n][faces];
	}

private:
	static const int MOD = 1e9 + 7;
};