#include <stdlib.h>

/*
image whatever value you choose between the max and min value
the moves will for max and min value will not change
so pair these max min values,I choose median as final value
*/

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

int minMoves2(int *nums, int numsSize)
{
	qsort(nums, numsSize, sizeof(int), cmp);
	int mid = nums[numsSize / 2], res = 0;
	for (int i = 0; i < numsSize; ++i)
		res += abs(nums[i] - mid);
	return res;
}