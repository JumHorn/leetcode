#include <stdlib.h>

int **mallocRes(int size, int *returnSize, int **returnColumnSizes)
{
	*returnSize = size;
	int **res = (int **)malloc(sizeof(int *) * (*returnSize));
	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
	{
		(*returnColumnSizes)[i] = i + 1;
		res[i] = (int *)malloc(sizeof(int) * ((*returnColumnSizes)[i]));
	}
	return res;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **generate(int numRows, int *returnSize, int **returnColumnSizes)
{
	int **res = mallocRes(numRows, returnSize, returnColumnSizes);
	if (numRows == 0)
		return res;
	res[0][0] = 1;
	for (int i = 1; i < numRows; ++i)
	{
		res[i][0] = 1;
		for (int j = 1; j < i; ++j)
			res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
		res[i][i] = 1;
	}
	return res;
}