#include <string.h>

int connectedCount(int **grid, int M, int N, int row, int col, int (*seen)[N])
{
	seen[row][col] = 1;
	int res = 1;
	int path[5] = {-1, 0, 1, 0, -1};
	for (int i = 0; i < 4; ++i)
	{
		int dx = row + path[i], dy = col + path[i + 1];
		if (dx >= 0 && dx < M && dy >= 0 && dy < N &&
			grid[dx][dy] != 0 && seen[dx][dy] == 0)
			res += connectedCount(grid, M, N, dx, dy, seen);
	}
	return res;
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

	int seen[M][N];
	memset(seen, 0, sizeof(seen));
	if (connectedCount(grid, M, N, land1 / N, land1 % N, seen) != count) //already disconnected
		return 0;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (grid[i][j] == 1)
			{
				memset(seen, 0, sizeof(seen));
				grid[i][j] = 0;
				int land = (land1 == i * N + j ? land2 : land1);
				if (connectedCount(grid, M, N, land / N, land % N, seen) != count - 1)
					return 1;
				grid[i][j] = 1;
			}
		}
	}
	return 2;
}