#include <stdlib.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int tallestBillboard(int *rods, int rodsSize)
{
	int dp[5001];
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i < rodsSize; ++i)
	{
		int pre_dp[5001];
		memcpy(pre_dp, dp, sizeof(dp));
		for (int j = 0; j < 5001; ++j)
		{
			if (pre_dp[j] == -1)
				continue;
			dp[j + rods[i]] = max(dp[j + rods[i]], pre_dp[j]);
			int delta = rods[i] >= j ? j : rods[i];
			dp[abs(j - rods[i])] = max(dp[abs(j - rods[i])], pre_dp[j] + delta);
		}
	}
	return dp[0];
}