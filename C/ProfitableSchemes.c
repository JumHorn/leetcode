#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int profitableSchemes(int G, int P, int *group, int groupSize, int *profit, int profitSize)
{
	static const int MOD = 1e9 + 7;
	int dp[G + 1][P + 1];
	memset(dp, 0, sizeof(dp));
	dp[0][0] = 1;
	for (int k = 0; k < groupSize; ++k)
	{
		for (int i = G - group[k]; i >= 0; --i)
		{
			for (int j = 0; j <= P; ++j)
				dp[i + group[k]][min(j + profit[k], P)] = (dp[i + group[k]][min(j + profit[k], P)] + dp[i][j]) % MOD;
		}
	}

	int res = 0;
	for (int i = 1; i <= G; ++i)
		res = (res + dp[i][P]) % MOD;
	return res;
}