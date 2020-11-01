#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize)
{
	*returnSize = numsSize;
	int* res = (int*)malloc(sizeof(int) * (*returnSize));
	for (int i = 0; i < indexSize; ++i)
	{
		for (int j = i + 1; j < indexSize; ++j)
		{
			if (index[i] >= index[j])
				++index[i];
		}
	}
	for (int i = 0; i < indexSize; ++i)
		res[index[i]] = nums[i];
	return res;
}
