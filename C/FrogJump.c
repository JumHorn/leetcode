#include <stdbool.h>
#include <string.h>

int dfs(int *stones, int stonesSize, int index, int k, int (*dp)[1101])
{
	if (index == stonesSize - 1)
		return 1;
	if (dp[index][k] != -1)
		return dp[index][k];
	for (int i = k > 1 ? k - 1 : 1, j = index + 1; i <= k + 1 && j < stonesSize; i++)
	{
		while (j < stonesSize && stones[j] < stones[index] + i)
			++j;
		if (j < stonesSize && stones[j] == stones[index] + i && dfs(stones, stonesSize, j, i, dp) == 1)
			return dp[index][k] = 1;
	}
	return dp[index][k] = 0;
}

bool canCross(int *stones, int stonesSize)
{
	int dp[stonesSize + 1][1101];
	memset(dp, -1, sizeof(dp));
	return dfs(stones, stonesSize, 0, 0, dp);
}