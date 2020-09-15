#include <string.h>

int uniquePathsWithObstacles(int **obstacleGrid, int obstacleGridSize, int *obstacleGridColSize)
{
	int m = obstacleGridSize, n = *obstacleGridColSize;
	int dp[n + 1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (obstacleGrid[i][j] == 1)
				dp[j + 1] = 0;
			else
				dp[j + 1] += dp[j];
		}
		dp[0] = 0;
	}
	return dp[n];
}