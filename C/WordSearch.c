#include <stdbool.h>

bool backTracking(char **board, int M, int N, int row, int col, char *word)
{
	if (!*word)
		return true;
	if (row < 0 || row >= M || col < 0 || col >= N)
		return false;
	if (*word != board[row][col])
		return false;
	board[row][col] = ~board[row][col]; //make it negative as seen
	//board backTracking direction
	int path[5] = {-1, 0, 1, 0, -1};
	for (int k = 0; k < 4; ++k)
	{
		int dx = row + path[k], dy = col + path[k + 1];
		if (backTracking(board, M, N, dx, dy, word + 1))
			return true;
	}
	board[row][col] = ~board[row][col];
	return false;
}

bool exist(char **board, int boardSize, int *boardColSize, char *word)
{
	int M = boardSize, N = *boardColSize;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
			if (backTracking(board, boardSize, *boardColSize, i, j, word))
				return true;
	}
	return false;
}