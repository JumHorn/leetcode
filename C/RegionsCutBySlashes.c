#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void split(int N, char (*board)[N], int row, int col, char sep)
{
	if (sep == '\\')
	{
		for (int k = 0; k < 3; ++k)
			board[row + k][col + k] = -1;
	}
	else if (sep == '/')
	{
		for (int k = 0; k < 3; ++k)
			board[row + k][col + 2 - k] = -1;
	}
}

void dfs(int N, char (*board)[N], int row, int col, int color)
{
	if (row < 0 || row >= N || col < 0 || col >= N || board[row][col] != 0)
		return;
	board[row][col] = color;
	//board dfs direction
	int path[5] = {-1, 0, 1, 0, -1};
	for (int i = 0; i < 4; ++i)
		dfs(N, board, row + path[i], col + path[i + 1], color);
}

int regionsBySlashes(char **grid, int gridSize)
{
	int N = gridSize * 3;
	char board[N][N];
	memset(board, 0, sizeof(board));
	for (int i = 0; i < gridSize; ++i)
	{
		for (int j = 0; j < gridSize; ++j)
			split(N, board, i * 3, j * 3, grid[i][j]);
	}

	int res = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (board[i][j] == 0)
				dfs(N, board, i, j, ++res);
		}
	}
	return res;
}