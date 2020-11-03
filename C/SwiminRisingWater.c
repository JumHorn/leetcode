#include <stdbool.h>
#include <string.h>

bool backTracking(int **grid, int N, int row, int col, int elevation, int (*seen)[N])
{
	seen[row][col] = 1;
	//board dfs direction
	int path[5] = {-1, 0, 1, 0, -1};
	for (int i = 0; i < 4; ++i)
	{
		int x = row + path[i], y = col + path[i + 1];
		if (x < 0 || x >= N || y < 0 || y >= N || seen[x][y] != 0 || grid[x][y] > elevation)
			continue;
		if (x == N - 1 && y == N - 1)
			return true;
		if (backTracking(grid, N, x, y, elevation, seen))
			return true;
	}
	return false;
}

int swimInWater(int **grid, int gridSize, int *gridColSize)
{
	int lo = grid[0][0], hi = gridSize * gridSize - 1;
	int seen[gridSize][gridSize];
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		memset(seen, 0, sizeof(seen));
		if (backTracking(grid, gridSize, 0, 0, mi, seen))
			hi = mi;
		else
			lo = mi + 1;
	}
	return lo;
}