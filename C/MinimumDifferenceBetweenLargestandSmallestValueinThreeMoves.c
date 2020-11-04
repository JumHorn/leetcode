#include <limits.h>
#include <stdlib.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
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
