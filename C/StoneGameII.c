#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int memdp(int *piles, int pilesSize, int index, int M, int (*dp)[pilesSize + 1])
{
	if (index >= pilesSize)
		return 0;
	if (dp[index][M] != -1)
		return dp[index][M];
	int res = 0, right = min(index + 2 * M, pilesSize);
	for (int i = index; i < right; ++i)
	{
		int current = piles[i] - ((index > 0) ? piles[index - 1] : 0);
		int sum = piles[pilesSize - 1] - piles[i];
		res = max(res, current + sum - memdp(piles, pilesSize, i + 1, max(i - index + 1, M), dp));
	}
	return dp[index][M] = res;
}

int stoneGameII(int *piles, int pilesSize)
{
	for (int i = 1; i < pilesSize; ++i)
		piles[i] += piles[i - 1];
	int dp[pilesSize + 1][pilesSize + 1];
	memset(dp, -1, sizeof(dp));
	return memdp(piles, pilesSize, 0, 1, dp);
}