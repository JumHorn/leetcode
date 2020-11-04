
int dfs(int **grid, int M, int N, int r, int c)
{
	if (r < 0 || r >= M || c < 0 || c >= N || grid[r][c] == 0)
		return 0;
	grid[r][c] = 0;
	int res = 1;
	int path[] = {-1, 0, 1, 0, -1};
	for (int i = 0; i < 4; ++i)
		res += dfs(grid, M, N, r + path[i], c + path[i + 1]);
	return res;
}

int maxAreaOfIsland(int **grid, int gridSize, int *gridColSize)
{
	if (gridSize == 0 || *gridColSize == 0)
		return 0;
	int res = 0;
	for (int i = 0; i < gridSize; ++i)
	{
		for (int j = 0; j < *gridColSize; ++j)
		{
			int val = dfs(grid, gridSize, *gridColSize, i, j);
			if (res < val)
				res = val;
		}
	}
	return res;
}
