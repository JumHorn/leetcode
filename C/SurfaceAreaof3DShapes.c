
#define max(a, b) (((a) > (b)) ? (a) : (b))

int surfaceArea(int **grid, int gridSize, int *gridColSize)
{
	int M = gridSize, N = *gridColSize, res = 0;
	//board dfs direction
	int path[5] = {-1, 0, 1, 0, -1};
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (grid[i][j] == 0)
				continue;
			for (int k = 0; k < 4; ++k)
			{
				int dx = i + path[k], dy = j + path[k + 1];
				if (dx >= 0 && dx < M && dy >= 0 && dy < N)
					res += max(0, grid[i][j] - grid[dx][dy]);
				else
					res += grid[i][j];
			}
			res += 2; //top bottom
		}
	}
	return res;
}