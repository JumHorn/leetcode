
int islandPerimeter(int **grid, int gridSize, int *gridColSize)
{
	int M = gridSize, N = *gridColSize, islands = 0, neighbours = 0;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (grid[i][j] == 1)
			{
				++islands; // count islands
				if (i < M - 1 && grid[i + 1][j] == 1)
					++neighbours; // count down neighbours
				if (j < N - 1 && grid[i][j + 1] == 1)
					++neighbours; // count right neighbours
			}
		}
	}
	return islands * 4 - neighbours * 2;
}