
int dfs(int **grid, int gridSize, int *gridColSize, int allzero, int row, int col)
{
	if (row < 0 || row >= gridSize || col < 0 || col >= *gridColSize)
		return 0;
	if (grid[row][col] == -1 || allzero < 0)
		return 0;
	if (grid[row][col] == 2)
		return allzero == 0 ? 1 : 0;
	int res = 0;
	grid[row][col] = -1;
	res += dfs(grid, gridSize, gridColSize, allzero - 1, row + 1, col);
	res += dfs(grid, gridSize, gridColSize, allzero - 1, row - 1, col);
	res += dfs(grid, gridSize, gridColSize, allzero - 1, row, col + 1);
	res += dfs(grid, gridSize, gridColSize, allzero - 1, row, col - 1);
	grid[row][col] = 0;
	return res;
}

int uniquePathsIII(int **grid, int gridSize, int *gridColSize)
{
	int allzero = 0, m, n;
	for (int i = 0; i < gridSize; ++i)
	{
		for (int j = 0; j < *gridColSize; ++j)
		{
			if (grid[i][j] == 1)
			{
				m = i;
				n = j;
			}
			else if (grid[i][j] == 0)
				++allzero;
		}
	}
	return dfs(grid, gridSize, gridColSize, allzero + 1, m, n); //for the start pos will consume count from allzero
}