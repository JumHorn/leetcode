#include <stdbool.h>
#include <stdlib.h>

#define swap(a, b) ((a) != (b) && ((a) ^= (b) ^= (a) ^= (b)))

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

void reverse(int *arr, int first, int last)
{
	for (; first < last; ++first, --last)
		swap(arr[first], arr[last]);
}

bool nextPermutation(int *nums, int numsSize)
{
	int i = numsSize;
	while (--i > 0)
	{
		if (nums[i] > nums[i - 1])
		{
			int j = numsSize - 1;
			while (nums[j] <= nums[i - 1])
				--j;
			swap(nums[i - 1], nums[j]);
			reverse(nums, i, numsSize - 1);
			return true;
		}
	}
	return false;
}

void addOneResult(int (*staticRes)[30], int *size, int *colSize, int *data, int dataSize)
{
	memcpy(staticRes[*size], data, sizeof(int) * dataSize);
	colSize[*size] = dataSize;
	++*size;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **permuteUnique(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
	static int staticRes[10000][30], staticResColSize[10000];
	*returnSize = 0;
	qsort(nums, numsSize, sizeof(int), cmp);
	do
	{
		addOneResult(staticRes, returnSize, staticResColSize, nums, numsSize);
	} while (nextPermutation(nums, numsSize));

	return mallocRes(staticRes, *returnSize, staticResColSize, returnSize, returnColumnSizes);
}