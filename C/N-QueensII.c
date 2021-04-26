#include <math.h>
#include <stdbool.h>

bool queenCheck(int *queen, int row, int column)
{
	for (int i = 0; i < row; ++i)
	{
		if (column == queen[i] || (abs(row - i) == abs(column - queen[i])))
			return false;
	}
	return true;
}

int backTracking(int *queen, int queenSize, int row)
{
	if (row >= queenSize)
		return 1;
	int res = 0;
	for (int j = 0; j < queenSize; ++j)
	{
		if (queenCheck(queen, row, j))
		{
			queen[row] = j;
			res += backTracking(queen, queenSize, row + 1);
		}
	}
	return res;
}

int totalNQueens(int n)
{
	int queen[n]; //record queens in each row
	return backTracking(queen, n, 0);
}