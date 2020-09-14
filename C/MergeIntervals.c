#include <limits.h>
#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	int *l = *(int **)lhs, *r = *(int **)rhs;
	if (l[0] != r[0])
		return l[0] - r[0];
	return r[1] - l[1];
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

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **merge(int **intervals, int intervalsSize, int *intervalsColSize, int *returnSize, int **returnColumnSizes)
{
	if (intervalsSize == 0)
	{
		*returnSize = 0;
		return NULL;
	}
	int data[intervalsSize][2], dataColSize[intervalsSize], dataSize = 0;
	qsort(intervals, intervalsSize, sizeof(int *), cmp);
	for (int i = 0, maxright = INT_MIN; i < intervalsSize; ++i)
	{
		if (intervals[i][0] > maxright)
			data[dataSize++][0] = intervals[i][0];
		if (intervals[i][1] > maxright)
			maxright = data[dataSize - 1][1] = intervals[i][1];
	}
	for (int i = 0; i < dataSize; ++i)
		dataColSize[i] = 2;
	return mallocRes(data, dataSize, dataColSize, returnSize, returnColumnSizes);
}