#include <string.h>

int countAndRestore(int **grid, int M, int N)
{
	int res = 0;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (grid[i][j] == 2)
			{
				grid[i][j] = 1;
				++res;
			}
		}
	}
	return res;
}

void markLand(int **grid, int M, int N, int row, int col)
{
	int path[5] = {-1, 0, 1, 0, -1};
	grid[row][col] = 2;
	for (int i = 0; i < 4; ++i)
	{
		int dx = row + path[i], dy = col + path[i + 1];
		if (dx >= 0 && dx < M && dy >= 0 && dy < N &&
			grid[dx][dy] != 0 && grid[dx][dy] != 2)
			markLand(grid, M, N, dx, dy);
	}
}

int minDays(int **grid, int gridSize, int *gridColSize)
{
	int M = gridSize, N = *gridColSize;
	int land1 = -1, land2 = -1, count = 0;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (grid[i][j] == 0)
				continue;
			if (land1 == -1)
				land1 = i * N + j;
			else if (land2 == -1)
				land2 = i * N + j;
			++count;
		}
	}
	if (count <= 1)
		return count;

	markLand(grid, M, N, land1 / N, land1 % N);
	if (countAndRestore(grid, M, N) != count) //already disconnected
		return 0;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (grid[i][j] == 1)
			{
				grid[i][j] = 0;
				int land = (land1 == i * N + j ? land2 : land1);
				markLand(grid, M, N, land / N, land % N);
				if (countAndRestore(grid, M, N) != count - 1) //already disconnected
					return 1;
				grid[i][j] = 1;
			}
		}
	}
	return 2;
}