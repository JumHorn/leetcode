#include <stdlib.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

bool stoneGame(int* piles, int pilesSize)
{
	int* sum = (int*)malloc((pilesSize + 1) * sizeof(int));
	memset(sum, 0, sizeof(int) * (pilesSize + 1));
	for (int i = 0; i < pilesSize; i++)
		sum[i + 1] = sum[i] + piles[i];
	int** dp = (int**)malloc(pilesSize * sizeof(int*));
	for (int i = 0; i < pilesSize; i++)
	{
		dp[i] = (int*)malloc(pilesSize * sizeof(int));
		memset(dp[i], 0, sizeof(int) * pilesSize);
	}
	for (int i = 0; i < pilesSize; i++)
		dp[i][i] = piles[i];
	for (int j = 0; j < pilesSize; j++)
		for (int i = j - 1; i >= 0; i--)
			dp[i][j] = max(sum[j + 1] - sum[i + 1] - dp[i + 1][j] + piles[i], sum[j] - sum[i] - dp[i][j - 1] + piles[j]);
	return dp[0][pilesSize - 1] > sum[pilesSize] / 2;
}

