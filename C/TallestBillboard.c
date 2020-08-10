#include <stdlib.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int tallestBillboard(int* rods, int rodsSize)
{
	int dp[5001];
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i < rodsSize; ++i)
	{
		int dp1[5001];
		memcpy(dp1, dp, sizeof(dp));
		for (int j = 0; j < 5001; ++j)
		{
			if (dp1[j] == -1)
				continue;
			dp[j + rods[i]] = max(dp[j + rods[i]], dp1[j]);
			int delta = rods[i] >= j ? j : rods[i];
			dp[abs(j - rods[i])] = max(dp[abs(j - rods[i])], dp1[j] + delta);
		}
	}
	return dp[0];
}
