#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **transpose(int **A, int ASize, int *AColSize, int *returnSize, int **returnColumnSizes)
{
	int M = ASize, N = *AColSize;
	*returnSize = N;
	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	for (int i = 0; i < N; ++i)
		(*returnColumnSizes)[i] = M;
	int **res = (int **)malloc(sizeof(int *) * (*returnSize));
	for (int i = 0; i < N; ++i)
		res[i] = (int *)malloc(sizeof(int) * (*returnColumnSizes)[i]);

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
			res[j][i] = A[i][j];
	}
	return res;
}