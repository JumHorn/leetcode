#include <stdbool.h>

bool rotting(int **grid, int gridSize, int colSize, int rotnum)
{
	bool res = false;
	for (int i = 0; i < gridSize; ++i)
	{
		for (int j = 0; j < colSize; ++j)
		{
			if (grid[i][j] == rotnum)
			{
				//board dfs direction
				int path[5] = {-1, 0, 1, 0, -1};
				for (int k = 0; k < 4; ++k)
				{
					int dx = i + path[k], dy = j + path[k + 1];
					if (dx >= 0 && dx < gridSize && dy >= 0 && dy < colSize && grid[dx][dy] == 1)
					{
						res = true;
						grid[dx][dy] = rotnum + 1;
					}
				}
			}
		}
	}
	return res;
}

bool checkGrid(int **grid, int gridSize, int colSize)
{
	for (int i = 0; i < gridSize; ++i)
	{
		for (int j = 0; j < colSize; ++j)
		{
			if (grid[i][j] == 1)
				return false;
		}
	}
	return true;
}

int orangesRotting(int **grid, int gridSize, int *gridColSize)
{
	int step = 0, rotnum = 1;
	while (rotting(grid, gridSize, gridColSize[0], ++rotnum))
		++step;
	if (!checkGrid(grid, gridSize, gridColSize[0]))
		return -1;
	return step;
}