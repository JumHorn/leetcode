#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *luckyNumbers(int **matrix, int matrixSize, int *matrixColSize, int *returnSize)
{
	int M = matrixSize, N = *matrixColSize;
	int row[M], col[N];
	for (int i = 0; i < M; ++i)
	{
		row[i] = 0;
		for (int j = 1; j < N; ++j)
		{
			if (matrix[i][j] < matrix[i][row[i]])
				row[i] = j;
		}
	}
	for (int j = 0; j < N; ++j)
	{
		col[j] = 0;
		for (int i = 1; i < M; ++i)
		{
			if (matrix[i][j] > matrix[col[j]][j])
				col[j] = i;
		}
	}
	int *res = (int *)malloc(sizeof(int) * (M * N));
	*returnSize = 0;
	for (int i = 0; i < M; ++i)
	{
		if (col[row[i]] == i)
			res[(*returnSize)++] = matrix[i][row[i]];
	}
	return res;
}