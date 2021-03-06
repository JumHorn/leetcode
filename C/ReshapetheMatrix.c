#include <stdlib.h>
#include <string.h>

//malloc result
int **mallocRes(int **data, int dataSize, int *dataColSize, int *returnSize, int **returnColumnSizes)
{
	*returnSize = dataSize;
	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	memcpy(*returnColumnSizes, dataColSize, sizeof(int) * (*returnSize));
	int **res = (int **)malloc(sizeof(int *) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
	{
		res[i] = (int *)malloc(sizeof(int) * ((*returnColumnSizes)[i]));
		memcpy(res[i], data[i], sizeof(int) * ((*returnColumnSizes)[i]));
	}
	return res;
}
/********end of malloc result********/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **matrixReshape(int **nums, int numsSize, int *numsColSize, int r, int c, int *returnSize, int **returnColumnSizes)
{
	int M = numsSize, N = *numsColSize;
	if (M * N != r * c)
		return mallocRes(nums, numsSize, numsColSize, returnSize, returnColumnSizes);

	*returnSize = r;
	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	for (int i = 0; i < r; ++i)
		(*returnColumnSizes)[i] = c;
	int **res = (int **)malloc(sizeof(int *) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
		res[i] = (int *)malloc(sizeof(int) * ((*returnColumnSizes)[i]));

	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int index = i * N + j;
			res[index / c][index % c] = nums[i][j];
		}
	}
	return res;
}