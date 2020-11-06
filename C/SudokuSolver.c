#include <stdbool.h>

bool checkBoard(char **board, int row, int col)
{
	for (int i = 0; i < 9; ++i)
	{
		if ((i != row && board[i][col] == board[row][col]) ||
			(i != col && board[row][i] == board[row][col]) ||
			((row / 3 * 3 + i / 3 != row || col / 3 * 3 + i % 3 != col) &&
			 board[row / 3 * 3 + i / 3][col / 3 * 3 + i % 3] == board[row][col]))
			return false;
	}
	return true;
}

bool backTracking(char **board, int boardSize)
{
	for (int i = 0; i < boardSize; ++i)
	{
		for (int j = 0; j < boardSize; ++j)
		{
			if (board[i][j] == '.')
			{
				for (char c = '1'; c <= '9'; ++c)
				{
					board[i][j] = c;
					if (checkBoard(board, i, j) && backTracking(board, boardSize))
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