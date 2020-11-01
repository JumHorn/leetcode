
int countNegatives(int** grid, int gridSize, int* gridColSize)
{
	int res = 0, M = gridSize, N = *gridColSize;
	for (int i = 0, j = N - 1; i < M; ++i)
	{
		while (j >= 0 && grid[i][j] < 0)
			--j;
		res += N - 1 - j;
	}
	return res;
}
