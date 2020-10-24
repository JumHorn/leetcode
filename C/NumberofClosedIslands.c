
int dfs(int** grid, int M, int N, int row, int col)
{
	if (row < 0 || row >= M || col < 0 || col >= N)
		return 0;
	if (grid[row][col] == 1)
		return 1;
	grid[row][col] = 1;
	//board dfs direction
	int path[5] = {-1, 0, 1, 0, -1};
	int res = 0;
	for (int i = 0; i < 4; ++i)
		res += dfs(grid, M, N, row + path[i], col + path[i + 1]);
	return res == 4 ? 1 : 0;
}

int closedIsland(int** grid, int gridSize, int* gridColSize)
{
	int res = 0, M = gridSize, N = *gridColSize;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (grid[i][j] == 0)
				res += dfs(grid, M, N, i, j);
		}
	}
	return res;
}
