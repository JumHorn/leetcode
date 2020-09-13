#include <stdbool.h>

/*
bit operation
we use low 12 bits of a int(at least 4 bit can store 1-9)
row  col  val
1111 1111 1111
row val encodes 1111 0000 1111
col val encodes 0000 1111 1111
sub val encodes 1111 1111 1111(subboard encodes with fixed prefix 1111 0000 0000)
*/

bool isValidSudoku(char **board, int boardSize, int *boardColSize)
{
	int hash[1 << 12] = {0};
	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (board[i][j] != '.')
			{
				int val = board[i][j] - '1';
				int row = ((i + 1) << 8) | val;
				int col = ((j + 1) << 4) | val;
				int sub = ((i / 3 * 3 + j / 3 % 3) << 4) | val | 0xF << 8;
				if (++hash[row] > 1 || ++hash[col] > 1 || ++hash[sub] > 1)
					return false;
			}
		}
	}
	return true;
}