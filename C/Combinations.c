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

void dfs(int start, int k, int n, int *data, int dataSize, int (*staticRes)[30], int *resSize, int *resColSize)
{
	if (k == 0)
	{
		addOneResult(staticRes, resSize, resColSize, data, dataSize);
		return;
	}
	for (int i = start; i <= n - k + 1; ++i)
	{
		data[dataSize] = i;
		dfs(i + 1, k - 1, n, data, dataSize + 1, staticRes, resSize, resColSize);
	}
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **combine(int n, int k, int *returnSize, int **returnColumnSizes)
{
	static int staticRes[10000][30], staticResColSize[10000];
	int data[30];
	*returnSize = 0;
	dfs(1, k, n, data, 0, staticRes, returnSize, staticResColSize);
	return mallocRes(staticRes, *returnSize, staticResColSize, returnSize, returnColumnSizes);
}