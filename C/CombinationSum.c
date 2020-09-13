#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

void addOneResult(int (*staticRes)[30], int *size, int *colSize, int *data, int dataSize)
{
	memcpy(staticRes[*size], data, sizeof(int) * dataSize);
	colSize[*size] = dataSize;
	++*size;
}

bool dfs(int *candidates, int candidatesSize, int index, int target, int *data, int dataSize, int (*staticRes)[30], int *size, int *colSize)
{
	if (target < 0)
		return true;
	if (target == 0)
	{
		addOneResult(staticRes, size, colSize, data, dataSize);
		return true;
	}
	for (int i = index; i < candidatesSize; ++i)
	{
		data[dataSize] = candidates[i];
		if (dfs(candidates, candidatesSize, i, target - candidates[i], data, dataSize + 1, staticRes, size, colSize))
			break;
	}
	return false;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **combinationSum(int *candidates, int candidatesSize, int target, int *returnSize, int **returnColumnSizes)
{
	static int staticRes[10000][30], staticResColSize[10000];
	int data[30];
	*returnSize = 0;
	qsort(candidates, candidatesSize, sizeof(int), cmp);
	dfs(candidates, candidatesSize, 0, target, data, 0, staticRes, returnSize, staticResColSize);

	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	memcpy(*returnColumnSizes, staticResColSize, sizeof(int) * (*returnSize));
	int **res = (int **)malloc(sizeof(int *) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
	{
		res[i] = (int *)malloc(sizeof(int) * ((*returnColumnSizes)[i]));
		memcpy(res[i], staticRes[i], sizeof(int) * ((*returnColumnSizes)[i]));
	}
	return res;
}