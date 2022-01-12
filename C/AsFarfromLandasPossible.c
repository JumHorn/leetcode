#include <limits.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int maxDistance(int **grid, int gridSize, int *gridColSize)
{
	int res = 0, N = gridSize;
	//down right
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (grid[i][j] == 1)
				continue;
			grid[i][j] = INT_MAX;
			if (i > 0)
				grid[i][j] = min(grid[i][j], grid[i - 1][j] + 1);
			if (j > 0)
				grid[i][j] = min(grid[i][j], grid[i][j - 1] + 1);
		}
	}
	//up left
	for (int i = N - 1; i >= 0; --i)
	{
		for (int j = N - 1; j >= 0; --j)
		{
			if (grid[i][j] == 1)
				continue;
			if (i < N - 1)
				grid[i][j] = min(grid[i][j], grid[i + 1][j] + 1);
			if (j < N - 1)
				grid[i][j] = min(grid[i][j], grid[i][j + 1] + 1);
			res = max(res, grid[i][j]);
		}
	}
	return res == INT_MAX ? -1 : res - 1;
}