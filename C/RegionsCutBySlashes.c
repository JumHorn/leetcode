#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char **createBoard(int size)
{
	char **board = (char **)malloc(sizeof(char *) * size);
	for (int i = 0; i < size; i++)
	{
		board[i] = (char *)malloc(sizeof(char) * size);
		memset(board[i], 0, sizeof(char) * size);
	}
	return board;
}

void split(char **board, int i, int j, char sep)
{
	if (sep == '\\')
	{
		for (int k = 0; k < 3; k++)
			board[i + k][j + k] = -1;
	}
	else if (sep == '/')
	{
		for (int k = 0; k < 3; k++)
			board[i + k][j + 2 - k] = -1;
	}
}

void dfs(char **board, int size, int i, int j, int label)
{
	if (board[i][j] != 0)
		return;
	board[i][j] = label;
	if (i - 1 >= 0)
		dfs(board, size, i - 1, j, label);
	if (i + 1 < size)
		dfs(board, size, i + 1, j, label);
	if (j - 1 >= 0)
		dfs(board, size, i, j - 1, label);
	if (j + 1 < size)
		dfs(board, size, i, j + 1, label);
}

void print(char **board, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			printf("%d ", (int)board[i][j]);
		printf("\n");
	}
}

int regionsBySlashes(char **grid, int gridSize)
{
	char **board = createBoard(gridSize * 3);
	for (int i = 0; i < gridSize; i++)
		for (int j = 0; j < gridSize; j++)
			split(board, i * 3, j * 3, grid[i][j]);

	//print(board, gridSize * 3);
	int res = 0;
	for (int i = 0; i < 3 * gridSize; i++)
		for (int j = 0; j < 3 * gridSize; j++)
		{
			if (board[i][j] == 0)
				dfs(board, gridSize * 3, i, j, ++res);
		}
	return res;
}

// int main()
// {
// 	char **grid = createBoard(2);
// 	grid[0][0] = '\\';
// 	grid[0][1] = '/';
// 	grid[1][0] = '/';
// 	grid[1][1] = '\\';
// 	regionsBySlashes(grid, 2);
// 	return 0;
// }