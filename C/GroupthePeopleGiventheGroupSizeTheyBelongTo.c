#include <stdlib.h>
#include <string.h>

int **mallocRes(int (*data)[500], int dataSize, int *dataColSize, int *returnSize, int **returnColumnSizes)
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
int **groupThePeople(int *groupSizes, int groupSizesSize, int *returnSize, int **returnColumnSizes)
{
	static int staticRes[500][500], staticResColSize[500];
	int hash[501][500] = {0}, hashColSize[501] = {0};
	*returnSize = 0;
	for (int i = 0; i < groupSizesSize; ++i)
		hash[groupSizes[i]][hashColSize[groupSizes[i]]++] = i;
	for (int i = 1; i <= 500; ++i)
	{
		if (hashColSize[i] == 0)
			continue;
		for (int j = 0; j < hashColSize[i]; j += i)
		{
			staticResColSize[*returnSize] = i;
			memcpy(staticRes[*returnSize], &hash[i][j], sizeof(int) * staticResColSize[*returnSize]);
			++*returnSize;
		}
	}
	return mallocRes(staticRes, *returnSize, staticResColSize, returnSize, returnColumnSizes);
}