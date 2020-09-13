#include <stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize)
{
	for (char c = '1'; c <= '9'; ++c)
	{
		for (int k = 0; k < 9; ++k)
		{
			int count = 0;
			for (int j = 0; j < 9; ++j)  //check row
			{
				if (board[k][j] == c)
					++count;
			}
			if (count > 1)
				return false;
			count = 0;
			for (int i = 0; i < 9; ++i)  //check col
			{
				if (board[i][k] == c)
					++count;
			}
			if (count > 1)
				return false;
			count = 0;
			for (int i = k / 3 * 3; i < k / 3 * 3 + 3; ++i)
			{
				for (int j = k % 3 * 3; j < k % 3 * 3 + 3; ++j)
				{
					if (board[i][j] == c)
						++count;
				}
			}
			if (count > 1)
				return false;
		}
	}
	return true;
}
