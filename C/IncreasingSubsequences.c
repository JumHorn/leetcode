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

void addOneResult(int (*staticRes)[30], int *size, int *colSize, int *data, int dataSize)
{
	memcpy(staticRes[*size], data, sizeof(int) * dataSize);
	colSize[(*size)++] = dataSize;
}

void dfs(int *nums, int numsSize, int index, int *instance, int instanceSize, int (*staticRes)[30], int *size, int *colSize)
{
	if (instanceSize > 1)
		addOneResult(staticRes, size, colSize, instance, instanceSize);
	int set[15], setSize = 0;
	for (int i = index; i < numsSize; ++i)
	{
		if (instanceSize == 0 || nums[i] >= instance[instanceSize - 1])
		{
			int j = setSize - 1;
			while (j >= 0 && set[j] != nums[i])
				--j;
			if (j < 0)
			{
				set[setSize++] = nums[i];
				instance[instanceSize] = nums[i];
				dfs(nums, numsSize, i + 1, instance, instanceSize + 1, staticRes, size, colSize);
			}
		}
	}
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **findSubsequences(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
	static int staticRes[1 << 15][30], staticResColSize[1 << 15];
	int data[30];
	*returnSize = 0;
	dfs(nums, numsSize, 0, data, 0, staticRes, returnSize, staticResColSize);
	return mallocRes(staticRes, *returnSize, staticResColSize, returnSize, returnColumnSizes);
}