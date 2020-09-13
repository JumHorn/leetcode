#include <stdbool.h>
#include <stdlib.h>

#define swap(a, b) ((a) ^= (b) ^= (a) ^= (b))

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

void reverse(int *arr, int first, int last)
{
	while (first < last)
	{
		swap(arr[first], arr[last]);
		++first;
		--last;
	}
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