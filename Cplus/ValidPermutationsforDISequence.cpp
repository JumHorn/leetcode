#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
	int numPermsDISequence(string S)
	{
		int n = S.length();
		vector<vector<int>> dp(n + 1, vector<int>(n + 1));
		dp[0][0] = 1;
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 0; j <= i; ++j)
			{
				if (S[i - 1] == 'D')
				{
					for (int k = j; k < i; k++)
						dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
				}
				else
				{
					for (int k = 0; k < j; k++)
						dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
				}
			}
		}
		int res = 0;
		for (int i = 0; i <= n; ++i)
			res = (res + dp[n][i]) % MOD;
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};