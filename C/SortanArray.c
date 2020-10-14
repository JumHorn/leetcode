#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortArray(int *nums, int numsSize, int *returnSize)
{
	*returnSize = numsSize;
	qsort(nums, numsSize, sizeof(int), cmp);
	return nums;
}