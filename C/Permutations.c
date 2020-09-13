#include <stdlib.h>

#define swap(a, b)  \
	if ((a) != (b)) \
	((a) ^= (b) ^= (a) ^= (b))

void addOneResult(int (*staticRes)[30], int *size, int *colSize, int *data, int dataSize)
{
	memcpy(staticRes[*size], data, sizeof(int) * dataSize);
	colSize[*size] = dataSize;
	++*size;
}

void dfs(int *nums, int numsSize, int index, int (*staticRes)[30], int *size, int *colSize)
{
	if (index >= numsSize)
		addOneResult(staticRes, size, colSize, nums, numsSize);
	for (int i = index; i < numsSize; ++i)
	{
		swap(nums[i], nums[index]);
		dfs(nums, numsSize, index + 1, staticRes, size, colSize);
		swap(nums[i], nums[index]);
	}
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **permute(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
	static int staticRes[10000][30], staticResColSize[10000];
	*returnSize = 0;
	dfs(nums, numsSize, 0, staticRes, returnSize, staticResColSize);

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