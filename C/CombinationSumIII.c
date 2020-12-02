#include <stdlib.h>

//malloc result
int **mallocRes(int (*data)[30], int dataSize, int *dataColSize, int *returnSize, int **returnColumnSizes)
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

void addOneResult(int (*staticRes)[30], int *resSize, int *resColSize, int *data, int dataSize)
{
	memcpy(staticRes[*resSize], data, sizeof(int) * dataSize);
	resColSize[*resSize] = dataSize;
	++*resSize;
}

void dfs(int n, int k, int index, int *instance, int instanceSize, int (*staticRes)[30], int *resSize, int *resColSize)
{
	if (n < 0)
		return;
	if (k == 0)
	{
		if (n == 0)
			addOneResult(staticRes, resSize, resColSize, instance, instanceSize);
		return;
	}
	for (int i = index; i <= 9; ++i)
	{
		instance[instanceSize] = i;
		dfs(n - i, k - 1, i + 1, instance, instanceSize + 1, staticRes, resSize, resColSize);
	}
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **combinationSum3(int k, int n, int *returnSize, int **returnColumnSizes)
{
	static int staticRes[1000][30], staticResColSize[1000];
	int instance[30];
	*returnSize = 0;
	dfs(n, k, 1, instance, 0, staticRes, returnSize, staticResColSize);
	return mallocRes(staticRes, *returnSize, staticResColSize, returnSize, returnColumnSizes);
}