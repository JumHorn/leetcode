#include <limits.h>
#include <stdlib.h>
#include <string.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

int threeSumClosest(int *nums, int numsSize, int target)
{
	qsort(nums, numsSize, sizeof(int), cmp);
	int diff = INT_MAX, res = 0;
	for (int i = 0; i < numsSize - 2; ++i)
	{
		//twoSum
		int j = i + 1, k = numsSize - 1;
		while (j < k)
		{
			int sum = nums[i] + nums[j] + nums[k];
			int val = abs(sum - target);
			if (val < diff)
			{
				diff = val;
				res = sum;
			}
			if (sum <= target)
				++j;
			else
				--k;
		}
	}
	return res;
}