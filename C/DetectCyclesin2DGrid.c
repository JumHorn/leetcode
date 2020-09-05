#include <stdbool.h>
#include <string.h>

bool dfs(char** grid, int M, int N, int (*seen)[N], int parent, int row, int col, char color, int mark)
{
	if (row < 0 || row >= M || col < 0 || col >= N)
		return false;
	if (grid[row][col] != color)
		return false;
	if (seen[row][col] != 0)
		return seen[row][col] == mark;
	seen[row][col] = mark;
	bool res = false;
	int path[5] = {-1, 0, 1, 0, -1};
	for (int i = 0; i < 4; ++i)
	{
		int x = row + path[i], y = col + path[i + 1];
		if (parent != x * N + y)
			res = res || dfs(grid, M, N, seen, row * N + col, x, y, color, mark);
	}
	return res;
}

bool containsCycle(char** grid, int gridSize, int* gridColSize)
{
	int M = gridSize, N = *gridColSize;
	int seen[M][N];
	memset(seen, 0, sizeof(seen));
	int mark = 1;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (seen[i][j] == 0)
			{
				if (dfs(grid, M, N, seen, -1, i, j, grid[i][j], mark))
					return true;
				++mark;
			}
		}
	}
	return false;
}
