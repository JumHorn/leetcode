
int projectionArea(int **grid, int gridSize, int *gridColSize)
{
	int M = gridSize, N = *gridColSize;
	int res = M * N; //top bottom
	//left,right
	for (int i = 0; i < M; ++i)
	{
		int max = 0;
		for (int j = 0; j < N; ++j)
		{
			if (max < grid[i][j])
				max = grid[i][j];
			if (grid[i][j] == 0) //remove empty
				res -= 1;
		}
		res += max;
	}
	//front back
	for (int j = 0; j < N; ++j)
	{
		int max = 0;
		for (int i = 0; i < M; ++i)
		{
			if (max < grid[i][j])
				max = grid[i][j];
		}
		res += max;
	}
	return res;
}