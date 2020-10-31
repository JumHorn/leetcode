#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

//malloc result
int **mallocRes(int (*data)[2], int dataSize, int *dataColSize, int *returnSize, int **returnColumnSizes)
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
int **minimumAbsDifference(int *arr, int arrSize, int *returnSize, int **returnColumnSizes)
{
	static int staticRes[10000][2], staticResColSize[10000];
	*returnSize = 0;
	qsort(arr, arrSize, sizeof(int), cmp);
	int diff = INT_MAX;
	for (int i = 1; i < arrSize; ++i)
		diff = min(diff, arr[i] - arr[i - 1]);
	for (int i = 1; i < arrSize; ++i)
	{
		if (diff == arr[i] - arr[i - 1])
		{
			staticRes[*returnSize][0] = arr[i - 1];
			staticRes[*returnSize][1] = arr[i];
			staticResColSize[*returnSize] = 2;
			++*returnSize;
		}
	}
	return mallocRes(staticRes, *returnSize, staticResColSize, returnSize, returnColumnSizes);
}