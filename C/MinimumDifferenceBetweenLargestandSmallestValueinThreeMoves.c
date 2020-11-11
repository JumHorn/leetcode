#include <limits.h>
#include <stdlib.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

int minDifference(int *nums, int numsSize)
{
	if (numsSize <= 4)
		return 0;
	qsort(nums, numsSize, sizeof(int), cmp);
	int res = INT_MAX;
	for (int i = 0, j = numsSize - 4; i <= 3; ++i, ++j)
		res = min(res, nums[j] - nums[i]);
	return res;
}