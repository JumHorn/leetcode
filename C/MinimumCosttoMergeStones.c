#include <limits.h>
#include <string.h>

/*
dp[i][j] means the minimum cost needed to merge stones[i] ~ stones[j].
dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
merge dp[i][k] as one pile and dp[k+1][j] as much as possible
*/

#define min(a, b) (((a) < (b)) ? (a) : (b))

int mergeStones(int *stones, int stonesSize, int K)
{
	if ((stonesSize - 1) % (K - 1) != 0)
		return -1;
	int sum[stonesSize + 1];
	sum[0] = 0;
	for (int i = 0; i < stonesSize; ++i)
		sum[i + 1] = sum[i] + stones[i];
	int dp[stonesSize][stonesSize];
	memset(dp, 0, sizeof(dp));
	for (int n = K; n <= stonesSize; ++n)
	{
		for (int i = 0, j = i + n - 1; j < stonesSize; ++i, ++j)
		{
			dp[i][j] = INT_MAX;
			for (int k = i; k < j; k += K - 1)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
			if ((j - i) % (K - 1) == 0)
				dp[i][j] += sum[j + 1] - sum[i];
		}
	}
	return dp[0][stonesSize - 1];
}