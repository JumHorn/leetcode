#include <stdbool.h>

bool dfs(char **board, int m, int n, int i, int j, char *word)
{
	if (!*word)
		return true;
	if (i < 0 || i >= m || j < 0 || j >= n)
		return false;
	if (*word != board[i][j])
		return false;
	char tmp = board[i][j];
	board[i][j] = ' ';
	int path[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
	for (int k = 0; k < 4; ++k)
	{
		int dx = i + path[k][0], dy = j + path[k][1];
		if (dfs(board, m, n, dx, dy, word + 1))
			return true;
	}
	board[i][j] = tmp;
	return false;
}

bool exist(char **board, int boardSize, int *boardColSize, char *word)
{
	int m = boardSize, n = *boardColSize;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
			if (dfs(board, boardSize, *boardColSize, i, j, word))
				return true;
	}
	return false;
}
