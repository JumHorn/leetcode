#include <stdlib.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

//malloc result
int **mallocRes(int M, int N, int *returnSize, int **returnColumnSizes)
{
	*returnSize = M;
	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	int **res = (int **)malloc(sizeof(int *) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
	{
		(*returnColumnSizes)[i] = N;
		res[i] = (int *)malloc(sizeof(int) * ((*returnColumnSizes)[i]));
	}
	return res;
}
/********end of malloc result********/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **restoreMatrix(int *rowSum, int rowSumSize, int *colSum, int colSumSize, int *returnSize, int **returnColumnSizes)
{
	int **res = mallocRes(rowSumSize, colSumSize, returnSize, returnColumnSizes);
	for (int i = 0; i < rowSumSize; ++i)
	{
		for (int j = 0; j < colSumSize; ++j)
		{
			res[i][j] = min(rowSum[i], colSum[j]);
			rowSum[i] -= res[i][j];
			colSum[j] -= res[i][j];
		}
	}
	return res;
}