#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

int longestConsecutive(int *nums, int numsSize)
{
	if (numsSize == 0)
		return 0;
	qsort(nums, numsSize, sizeof(int), cmp);
	int res = 0, count = 1;
	for (int i = 1; i < numsSize; ++i)
	{
		if (nums[i] != nums[i - 1] && nums[i] != nums[i - 1] + 1)
		{
			res = max(res, count);
			count = 0;
		}
		if (nums[i] != nums[i - 1])
			++count;
	}
	return max(res, count);
}
