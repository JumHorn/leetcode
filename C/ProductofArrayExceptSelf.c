#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *productExceptSelf(int *nums, int numsSize, int *returnSize)
{
	*returnSize = numsSize;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	//use res as prefix product
	res[0] = nums[0];
	for (int i = 1; i < numsSize; ++i)
		res[i] = res[i - 1] * nums[i];
	//calcu nums as suffix product
	for (int i = numsSize - 2; i >= 0; --i)
		nums[i] *= nums[i + 1];
	res[numsSize - 1] = res[numsSize - 2];
	for (int i = numsSize - 2; i > 0; --i)
		res[i] = nums[i + 1] * res[i - 1];
	res[0] = nums[1];
	return res;
}