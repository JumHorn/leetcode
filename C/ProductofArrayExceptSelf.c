#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize)
{
	*returnSize = numsSize;
	int* res = (int*)malloc(sizeof(int) * (*returnSize));
	int product = 1, zero = 0, index;
	for (int i = 0; i < numsSize; ++i)
	{
		if (nums[i] == 0)
		{
			++zero;
			index = i;
		}
		else
			product *= nums[i];
	}
	if (zero > 0)
		memset(res, 0, sizeof(int) * (*returnSize));
	if (zero == 1)
		res[index] = product;
	else if (zero == 0)
	{
		for (int i = 0; i < numsSize; ++i)
			res[i] = product / nums[i];
	}
	return res;
}
