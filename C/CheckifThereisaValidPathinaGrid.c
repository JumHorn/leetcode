#include <stdbool.h>
#include <string.h>

bool dfs(int M, int N, int (*board)[N], int row, int col)
{
	if (row < 0 || row >= M || col < 0 || col >= N || board[row][col] == 0)
		return false;
	board[row][col] = 0;
	if (row == M - 2 && col == N - 2)
		return true;
	//board dfs direction
	int path[5] = {-1, 0, 1, 0, -1};
	bool res = false;
	for (int i = 0; i < 4; ++i)
		res = res || dfs(M, N, board, row + path[i], col + path[i + 1]);
	return res;
}

bool hasValidPath(int **grid, int gridSize, int *gridColSize)
{
	int M = gridSize, N = *gridColSize;
	int board[3 * M][3 * N];
	memset(board, 0, sizeof(board));
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int x = 3 * i + 1, y = 3 * j + 1;
			if (grid[i][j] == 1)
				board[x][y - 1] = board[x][y] = board[x][y + 1] = 1;
			else if (grid[i][j] == 2)
				board[x - 1][y] = board[x][y] = board[x + 1][y] = 1;
			else if (grid[i][j] == 3)
				board[x][y - 1] = board[x][y] = board[x + 1][y] = 1;
			else if (grid[i][j] == 4)
				board[x][y + 1] = board[x][y] = board[x + 1][y] = 1;
			else if (grid[i][j] == 5)
				board[x - 1][y] = board[x][y] = board[x][y - 1] = 1;
			else
				board[x - 1][y] = board[x][y] = board[x][y + 1] = 1;
		}
	}
	return dfs(3 * M, 3 * N, board, 1, 1);
}