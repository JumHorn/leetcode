#include <string.h>

int countServers(int** grid, int gridSize, int* gridColSize)
{
	int M = gridSize, N = *gridColSize;
	int row[M], col[N];  //sum of row,col servers
	memset(row, 0, sizeof(row));
	memset(col, 0, sizeof(col));
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			row[i] += grid[i][j];
			col[j] += grid[i][j];
		}
	}

	int res = 0;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (grid[i][j] == 1 && row[i] + col[j] > 2)
				++res;
		}
	}
	return res;
}
