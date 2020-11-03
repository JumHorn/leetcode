#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char ***addQueen(char ***queens, int size, char **newqueen)
{
	queens = (char ***)realloc(queens, size * sizeof(char **));
	queens[size - 1] = newqueen;
	return queens;
}

char **createQueen(int n, int *queen)
{
	char **res = (char **)malloc(sizeof(char *) * n);
	for (int i = 0; i < n; ++i)
	{
		res[i] = (char *)malloc(sizeof(char) * (n + 1));
		for (int j = 0; j < n; j++)
			res[i][j] = '.';
		res[i][queen[i]] = 'Q';
		res[i][n] = '\0';
	}
	return res;
}

bool queenCheck(int *queen, int row)
{
	for (int i = 0; i < row; ++i)
	{
		if (queen[i] == queen[row] || abs(i - row) == abs(queen[i] - queen[row]))
			return false;
	}
	return true;
}

bool backTracking(int n, int *queen, int i, char ****queens, int *size)
{
	if (i >= n)
		return true;
	for (int j = queen[i]; j < n; j++)
	{
		queen[i] = j;
		if (queenCheck(queen, i))
		{
			if (backTracking(n, queen, i + 1, queens, size) && i == n - 1)
			{
				char **newqueen = (char **)createQueen(n, queen);
				*queens = addQueen(*queens, ++(*size), newqueen);
			}
		}
		queen[i] = 0;
	}
	return false;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char ***solveNQueens(int n, int *returnSize, int **returnColumnSizes)
{
	int queen[n];
	memset(queen, 0, sizeof(queen));
	*returnSize = 0;
	char ***res = NULL;
	backTracking(n, queen, 0, &res, returnSize);
	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
		(*returnColumnSizes)[i] = n;
	return res;
}