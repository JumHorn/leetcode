#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize)
{
	*returnSize = numsSize;
	if (numsSize == 0)
		return NULL;
	int* res = (int*)malloc(sizeof(int) * (*returnSize));
	memset(res, -1, sizeof(int) * (*returnSize));
	int stack[numsSize * 2], top = -1;
	for (int i = 0; i < 2 * numsSize; ++i)
	{
		while (top != -1 && nums[stack[top]] < nums[i % numsSize])
		{
			res[stack[top]] = nums[i % numsSize];
			--top;
		}
		stack[++top] = i % numsSize;
	}
	return res;
}
