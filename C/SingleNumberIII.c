#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize)
{
	*returnSize = 2;
	int* res = (int*)malloc(sizeof(int) * (*returnSize));
	int XOR = 0;
	res[0] = res[1] = 0;
	for (int i = 0; i < numsSize; ++i)
		XOR ^= nums[i];
	int rightmostbit = (XOR & -XOR);
	for (int i = 0; i < numsSize; ++i)
	{
		if (rightmostbit & nums[i])
			res[0] ^= nums[i];
		else
			res[1] ^= nums[i];
	}
	return res;
}
