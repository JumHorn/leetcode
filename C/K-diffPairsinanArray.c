#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

int findPairs(int *nums, int numsSize, int k)
{
	qsort(nums, numsSize, sizeof(int), cmp);
	int res = 0;
	for (int i = 1, j = 0; i < numsSize; ++i)
	{
		while (nums[i] - nums[j] > k)
			++j;
		if (i != j && nums[i] - nums[j] == k)
		{
			++res;
			++j;
			while (j < numsSize && nums[j] == nums[j - 1])
				++j;
			if (i < j)
				i = j;
		}
	}
	return res;
}
