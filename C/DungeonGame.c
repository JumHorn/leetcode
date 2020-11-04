#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int calculateMinimumHP(int **dungeon, int dungeonSize, int *dungeonColSize)
{
	int m = dungeonSize, n = *dungeonColSize;
	int dp[m + 1][n + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = m - 2; i >= 0; --i)
		dp[i][n] = -1000000;
	for (int j = n - 2; j >= 0; --j)
		dp[m][j] = -1000000;
	for (int i = m - 1; i >= 0; --i)
	{
		for (int j = n - 1; j >= 0; --j)
		{
			dp[i][j] = max(dp[i][j + 1], dp[i + 1][j]) + dungeon[i][j];
			if (dp[i][j] > 0)
				dp[i][j] = 0;
		}
	}
	return 1 - dp[0][0];
}
