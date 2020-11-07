#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char **createQueen(int *queen, int queenSize)
{
	char **res = (char **)malloc(sizeof(char *) * queenSize);
	for (int i = 0; i < queenSize; ++i)
	{
		res[i] = (char *)malloc(sizeof(char) * (queenSize + 1));
		memset(res[i], '.', sizeof(char) * queenSize);
		res[i][queen[i]] = 'Q';
		res[i][queenSize] = '\0';
	}
	return res;
}

bool queenCheck(int *queen, int row, int column)
{
	for (int i = 0; i < row; ++i)
	{
		if (column == queen[i] || (abs(row - i) == abs(column - queen[i])))
			return false;
	}
	return true;
}

void dfs(int *queen, int queenSize, int row, char ***res, int *resSize)
{
	if (row >= queenSize) //create queen
		res[(*resSize)++] = createQueen(queen, queenSize);
	for (int j = 0; j < queenSize; ++j)
	{
		if (queenCheck(queen, row, j))
		{
			queen[row] = j;
			dfs(queen, queenSize, row + 1, res, resSize);
		}
	}
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char ***solveNQueens(int n, int *returnSize, int **returnColumnSizes)
{
	int queen[n];
	*returnSize = 0;
	char ***res = (char ***)malloc(sizeof(char **) * 1000);
	dfs(queen, n, 0, res, returnSize);
	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
		(*returnColumnSizes)[i] = n;
	return res;
}