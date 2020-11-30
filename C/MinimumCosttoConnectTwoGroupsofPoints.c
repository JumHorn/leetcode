#include <limits.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int connectTwoGroups(int **cost, int costSize, int *costColSize)
{
	int size1 = costSize, size2 = *costColSize, bitmask = (1 << size2) - 1;
	int dp[size1 + 1][bitmask + 1];
	memset(dp, 1 << 6, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 0; i < size1; ++i)
	{
		for (int mask = 0; mask <= bitmask; ++mask)
		{
			for (int j = 0; j < size2; ++j)
				dp[i + 1][mask | 1 << j] = min(dp[i + 1][mask | 1 << j], dp[i][mask] + cost[i][j]);
		}
	}
	int mincost[size2];
	memset(mincost, 1 << 6, sizeof(mincost));
	for (int i = 0; i < size1; ++i)
	{
		for (int j = 0; j < size2; ++j)
			mincost[j] = min(mincost[j], cost[i][j]);
	}
	int res = INT_MAX;
	for (int i = 0; i <= bitmask; ++i)
	{
		int val = dp[size1][i];
		for (int j = 0; j < size2; ++j)
		{
			if (((1 << j) & i) == 0)
				val += mincost[j];
		}
		res = min(res, val);
	}
	return res;
}