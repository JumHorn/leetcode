#include <string.h>

int memdp(int** grid, int N, int first, int second, int (*dp)[N * N])
{
	if (dp[first][second] != -1)
		return dp[first][second];
	int x1 = first / N, y1 = first % N, x2 = second / N, y2 = second % N;
	if (first == N * N - 1)
		return grid[N - 1][N - 1];
	int path[][2] = {{1, 0}, {0, 1}};
	int res = -N * N, current = 0;
	current += grid[x1][y1];
	if (first != second)
		current += grid[x2][y2];
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			int dx1 = x1 + path[i][0];
			int dy1 = y1 + path[i][1];
			int dx2 = x2 + path[j][0];
			int dy2 = y2 + path[j][1];
			if (dx1 >= N || dy1 >= N || dx2 >= N || dy2 >= N || grid[dx1][dy1] == -1 || grid[dx2][dy2] == -1)
				continue;
			int tmp = memdp(grid, N, dx1 * N + dy1, dx2 * N + dy2, dp) + current;
			if (res < tmp)
				res = tmp;
		}
	}
	return dp[first][second] = res;
}

int cherryPickup(int** grid, int gridSize, int* gridColSize)
{
	if (gridSize == 1)
		return grid[0][0];
	int n = gridSize * gridSize;
	int dp[n][n];
	memset(dp, -1, sizeof(dp));
	memdp(grid, gridSize, 0, 0, dp);
	return dp[0][0] < 0 ? 0 : dp[0][0];
}
