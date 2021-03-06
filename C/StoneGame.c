#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

bool stoneGame(int *piles, int pilesSize)
{
	int sum[pilesSize + 1];
	sum[0] = 0;
	for (int i = 0; i < pilesSize; ++i)
		sum[i + 1] = sum[i] + piles[i];
	int dp[pilesSize][pilesSize];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < pilesSize; ++i)
		dp[i][i] = piles[i];
	for (int j = 0; j < pilesSize; ++j)
	{
		for (int i = j - 1; i >= 0; --i)
			dp[i][j] = max(sum[j + 1] - sum[i + 1] - dp[i + 1][j] + piles[i], sum[j] - sum[i] - dp[i][j - 1] + piles[j]);
	}
	return dp[0][pilesSize - 1] > sum[pilesSize] / 2;
}