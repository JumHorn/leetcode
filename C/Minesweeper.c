#include <stdlib.h>

//malloc result
char **mallocRes(char **data, int dataSize, int *dataColSize, int *returnSize, int **returnColumnSizes)
{
	*returnSize = dataSize;
	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	memcpy(*returnColumnSizes, dataColSize, sizeof(int) * (*returnSize));
	char **res = (char **)malloc(sizeof(char *) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
	{
		res[i] = (char *)malloc(sizeof(char) * ((*returnColumnSizes)[i]));
		memcpy(res[i], data[i], sizeof(char) * ((*returnColumnSizes)[i]));
	}
	return res;
}
/********malloc result********/

void dfs(char **board, int M, int N, int row, int col)
{
	if (row < 0 || row >= M || col < 0 || col >= N)
		return;
	if (board[row][col] != 'E')
		return;
	board[row][col] = 'B';
	int mine = mineCount(board, M, N, row, col);
	if (mine != 0)
	{
		board[row][col] = '0' + mine;
		return;
	}
	int path[][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
	for (int i = 0; i < 8; ++i)
		dfs(board, M, N, row + path[i][0], col + path[i][1]);
}

int mineCount(char **board, int M, int N, int row, int col)
{
	int res = 0;
	for (int i = row - 1; i <= row + 1; ++i)
	{
		for (int j = col - 1; j <= col + 1; ++j)
		{
			if (i < 0 || i >= M || j < 0 || j >= N)
				continue;
			if (board[i][j] == 'M')
				++res;
		}
	}
	return res;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char **updateBoard(char **board, int boardSize, int *boardColSize, int *click, int clickSize, int *returnSize, int **returnColumnSizes)
{
	if (board[click[0]][click[1]] == 'M')
		board[click[0]][click[1]] = 'X';
	else if (board[click[0]][click[1]] == 'E')
		dfs(board, boardSize, *boardColSize, click[0], click[1]);
	return mallocRes(board, boardSize, boardColSize, returnSize, returnColumnSizes);
}