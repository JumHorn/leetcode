
void dfs(char** grid, int M, int N, int row, int col)
{
	if (row < 0 || row >= M || col < 0 || col >= N)
		return;
	if (grid[row][col] != '1')
		return;
	grid[row][col] = '0';
	int path[] = {-1, 0, 1, 0, -1};
	for (int i = 0; i < 4; ++i)
		dfs(grid, M, N, row + path[i], col + path[i + 1]);
}

int numIslands(char** grid, int gridSize, int* gridColSize)
{
	int res = 0;
	for (int i = 0; i < gridSize; ++i)
	{
		for (int j = 0; j < *gridColSize; ++j)
		{
			if (grid[i][j] == '1')
			{
				++res;
				dfs(grid, gridSize, *gridColSize, i, j);
			}
		}
	}
	return res;
}
