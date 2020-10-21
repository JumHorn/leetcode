
#define min(a, b) (((a) < (b)) ? (a) : (b))

int largest1BorderedSquare(int** grid, int gridSize, int* gridColSize)
{
	int dp[102][102][4] = {{{0}}};
	int M = gridSize, N = *gridColSize;
	for (int i = 0; i < M; ++i)  //up
	{
		for (int j = 0; j < N; ++j)
		{
			if (grid[i][j] == 1)
				dp[i + 1][j + 1][0] = dp[i][j + 1][0] + 1;
		}
	}
	for (int i = M - 1; i >= 0; --i)  //down
	{
		for (int j = 0; j < N; ++j)
		{
			if (grid[i][j] == 1)
				dp[i + 1][j + 1][1] = dp[i + 2][j + 1][1] + 1;
		}
	}
	for (int j = 0; j < N; ++j)
	{
		for (int i = 0; i < M; ++i)  //left
		{
			if (grid[i][j] == 1)
				dp[i + 1][j + 1][2] = dp[i + 1][j][2] + 1;
		}
	}
	for (int j = N - 1; j >= 0; --j)
	{
		for (int i = 0; i < M; ++i)  //right
		{
			if (grid[i][j] == 1)
				dp[i + 1][j + 1][3] = dp[i + 1][j + 2][3] + 1;
		}
	}

	int res = 0;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (grid[i][j] == 1)
			{
				int size = min(dp[i + 1][j + 1][1], dp[i + 1][j + 1][3]);
				for (int k = res; k < size; ++k)
				{
					if (dp[i + k + 1][j + k + 1][0] >= k && dp[i + k + 1][j + k + 1][2] >= k)
						res = k + 1;
				}
			}
		}
	}
	return res * res;
}
