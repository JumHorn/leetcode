#include <memory>
using namespace std;

class Solution
{
public:
	int distinctSequences(int n)
	{
		int dp[6][6], next_dp[6][6];
		memset(dp, 0, sizeof(dp));
		memset(next_dp, 0, sizeof(next_dp));
		if (n == 1)
			return 6;
		if (n == 2)
			return 22;
		//init
		for (int i = 0; i < 6; ++i)
		{
			for (int j = 0; j < 6; ++j)
			{
				if (i == j || gcd(i + 1, j + 1) > 1)
					continue;
				dp[i][j] = 1;
			}
		}

		for (int i = 3; i <= n; ++i)
		{
			for (int a = 0; a < 6; ++a)
			{
				for (int b = 0; b < 6; ++b)
				{
					for (int c = 0; c < 6; ++c)
					{
						if (c == a || c == b || gcd(c + 1, b + 1) > 1)
							continue;
						next_dp[b][c] = (next_dp[b][c] + dp[a][b]) % MOD;
					}
				}
			}
			memcpy(dp, next_dp, sizeof(dp));
			memset(next_dp, 0, sizeof(next_dp));
		}

		long long res = 0;
		for (int i = 0; i < 6; ++i)
		{
			for (int j = 0; j < 6; ++j)
				res = (res + dp[i][j]) % MOD;
		}
		return res;
	}

	int gcd(int x, int y)
	{
		return x == 0 ? y : gcd(y % x, x);
	}

private:
	static const int MOD = 1e9 + 7;
};