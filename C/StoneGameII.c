#include <string.h>
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int dfs(int *piles, int pilesSize, int **dp, int index, int M)
{
	if (index >= pilesSize)
		return 0;
	if (dp[index][M] != -1)
		return dp[index][M];
	int res = 0, right = min(index + 2 * M, pilesSize);
	for (int i = index; i < right; i++)
	{
		int current = piles[i] - ((index > 0) ? piles[index - 1] : 0);
		int sum = piles[pilesSize - 1] - piles[i];
		res = max(res, current + sum - dfs(piles, pilesSize, dp, i + 1, max(i - index + 1, M)));
	}
	dp[index][M] = res;
	return res;
}

int stoneGameII(int *piles, int pilesSize)
{
	for (int i = 1; i < pilesSize; i++)
		piles[i] += piles[i - 1];
	int **dp = (int *)malloc(sizeof(int *) * (pilesSize + 1));
	for (int i = 0; i <= pilesSize; i++)
	{
		dp[i] = (int *)malloc(sizeof(int) * (pilesSize + 1));
		memset(dp[i], -1, sizeof(int) * (pilesSize + 1));
	}
	return dfs(piles, pilesSize, dp, 0, 1);
}