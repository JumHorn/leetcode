#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int cherryPickup(int **grid, int gridSize, int *gridColSize)
{
	int M = gridSize, N = *gridColSize;
	int dp[M][N][N];
	memset(dp, -1, sizeof(dp));
	dp[0][0][N - 1] = grid[0][0] + grid[0][N - 1];
	for (int m = 1; m < M; ++m)
	{
		for (int bot0 = 0; bot0 < N; ++bot0)
		{
			for (int bot1 = bot0; bot1 < N; ++bot1)
			{
				for (int i = max(bot0 - 1, 0); i <= min(bot0 + 1, N - 1); ++i)
				{
					for (int j = max(bot1 - 1, 0); j <= min(bot1 + 1, N - 1); j++)
					{
						if (dp[m - 1][i][j] < 0)
							continue;
						if (bot0 == bot1)
							dp[m][bot0][bot1] = max(dp[m][bot0][bot1], dp[m - 1][i][j] + grid[m][bot0]);
						else
							dp[m][bot0][bot1] = max(dp[m][bot0][bot1], dp[m - 1][i][j] + grid[m][bot0] + grid[m][bot1]);
					}
				}
			}
		}
	}

	int res = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = i; j < N; ++j)
			res = max(res, dp[M - 1][i][j]);
	}
	return res;
}
