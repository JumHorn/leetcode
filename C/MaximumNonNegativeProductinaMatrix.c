
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int maxProductPath(int** grid, int gridSize, int* gridColSize)
{
	static const int MOD = 1e9 + 7;
	int M = gridSize, N = *gridColSize;
	long dp[M][N][2];
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (i == 0 && j == 0)
				dp[i][j][0] = dp[i][j][1] = grid[0][0];
			else if (i == 0)
				dp[i][j][0] = dp[i][j][1] = grid[i][j] * dp[i][j - 1][0];
			else if (j == 0)
				dp[i][j][0] = dp[i][j][1] = grid[i][j] * dp[i - 1][j][0];
			else
			{
				long a = grid[i][j] * max(dp[i][j - 1][0], dp[i - 1][j][0]);
				long b = grid[i][j] * min(dp[i][j - 1][1], dp[i - 1][j][1]);
				dp[i][j][0] = max(a, b);
				dp[i][j][1] = min(a, b);
			}
		}
	}
	return dp[M - 1][N - 1][0] < 0 ? -1 : dp[M - 1][N - 1][0] % MOD;
}
