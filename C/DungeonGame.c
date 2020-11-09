#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int calculateMinimumHP(int **dungeon, int dungeonSize, int *dungeonColSize)
{
	int M = dungeonSize, N = *dungeonColSize;
	int dp[M + 1][N + 1];
	memset(dp, 1 << 6, sizeof(dp));
	dp[M - 1][N] = dp[M][N - 1] = 0;
	for (int i = M - 1; i >= 0; --i)
	{
		for (int j = N - 1; j >= 0; --j)
			dp[i][j] = max(min(dp[i][j + 1], dp[i + 1][j]) - dungeon[i][j], 0);
	}
	return dp[0][0] + 1;
}