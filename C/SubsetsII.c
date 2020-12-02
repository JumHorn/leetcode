#include <stdlib.h>

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

void addOneResult(int (*staticRes)[30], int *resSize, int *resColSize, int *data, int dataSize)
{
	memcpy(staticRes[*resSize], data, sizeof(int) * dataSize);
	resColSize[*resSize] = dataSize;
	++*resSize;
}

void dfs(int *nums, int numsSize, int index, int *data, int dataSize, int (*staticRes)[30], int *resSize, int *resColSize)
{
	addOneResult(staticRes, resSize, resColSize, data, dataSize);
	for (int i = index; i < numsSize; ++i)
	{
		if (i != index && nums[i] == nums[i - 1]) //remove dumplicate
			continue;
		data[dataSize] = nums[i];
		dfs(nums, numsSize, i + 1, data, dataSize + 1, staticRes, resSize, resColSize);
	}
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **subsetsWithDup(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
	static int staticRes[10000][30], staticResColSize[10000];
	int data[30];
	qsort(nums, numsSize, sizeof(int), cmp);
	*returnSize = 0;
	dfs(nums, numsSize, 0, data, 0, staticRes, returnSize, staticResColSize);
	return mallocRes(staticRes, *returnSize, staticResColSize, returnSize, returnColumnSizes);
}