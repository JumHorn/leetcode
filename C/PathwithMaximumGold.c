
int dfs(int** grid, int M, int N, int row, int col)
{
	int res = 0;
	if (row < 0 || row >= M || col < 0 || col >= N || grid[row][col] == 0)
		return res;
	//board dfs direction
	int path[5] = {-1, 0, 1, 0, -1};
	for (int i = 0; i < 4; ++i)
	{
		int gold = grid[row][col];
		grid[row][col] = 0;
		int val = dfs(grid, M, N, row + path[i], col + path[i + 1]) + gold;
		if (res < val)
			res = val;
		grid[row][col] = gold;
	}
	return res;
}

int getMaximumGold(int** grid, int gridSize, int* gridColSize)
{
	int res = 0, M = gridSize, N = *gridColSize;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (grid[i][j] != 0)
			{
				int val = dfs(grid, M, N, i, j);
				if (res < val)
					res = val;
			}
		}
	}
	return res;
}
