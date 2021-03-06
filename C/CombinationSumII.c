#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

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
/********end of malloc result********/

void addOneResult(int (*staticRes)[30], int *resSize, int *resColSize, int *data, int dataSize)
{
	memcpy(staticRes[*resSize], data, sizeof(int) * dataSize);
	resColSize[*resSize] = dataSize;
	++*resSize;
}

bool dfs(int *candidates, int candidatesSize, int index, int target, int *data, int dataSize, int (*staticRes)[30], int *resSize, int *resColSize)
{
	if (target < 0)
		return true;
	if (target == 0)
	{
		addOneResult(staticRes, resSize, resColSize, data, dataSize);
		return true;
	}
	for (int i = index; i < candidatesSize; ++i)
	{
		if (i != index && candidates[i] == candidates[i - 1]) //remove dumplicate
			continue;
		data[dataSize] = candidates[i];
		if (dfs(candidates, candidatesSize, i + 1, target - candidates[i], data, dataSize + 1, staticRes, resSize, resColSize))
			break;
	}
	return false;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **combinationSum2(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes)
{
	static int staticRes[10000][30], staticResColSize[10000];
	int data[30];
	*returnSize = 0;
	qsort(candidates, candidatesSize, sizeof(int), cmp);
	dfs(candidates, candidatesSize, 0, target, data, 0, staticRes, returnSize, staticResColSize);
	return mallocRes(staticRes, *returnSize, staticResColSize, returnSize, returnColumnSizes);
}