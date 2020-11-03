#include <stdbool.h>

bool checkBoard(char **board, int i, int j)
{
	for (int l = 0; l < 9; l++)
	{
		if (l != i && board[l][j] == board[i][j])
			return false;
		if (l != j && board[i][l] == board[i][j])
			return false;
		if ((i / 3 * 3 + l / 3 != i || j / 3 * 3 + l % 3 != j) && board[i / 3 * 3 + l / 3][j / 3 * 3 + l % 3] == board[i][j])
			return false;
	}
	return true;
}

bool backTracking(char **board, int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; j++)
		{
			if (board[i][j] == '.')
			{
				for (char c = '1'; c <= '9'; c++)
				{
					board[i][j] = c;
					if (checkBoard(board, i, j) && backTracking(board, n))
						return true;
					board[i][j] = '.';
				}
				return false;
			}
		}
	}
	return true;
}

void solveSudoku(char **board, int boardSize, int *boardColSize)
{
	backTracking(board, boardSize);
}
