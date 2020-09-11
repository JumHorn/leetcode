#include <limits.h>
#include <stdlib.h>
#include <string.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

int threeSumClosest(int *nums, int numsSize, int target)
{
	qsort(nums, numsSize, sizeof(int), cmp);
	int diff = INT_MAX, res = 0;
	for (int i = 0, pre = INT_MIN; i < numsSize - 2; pre = nums[i++])
	{
		if (nums[i] == pre)
			continue;
		//twoSum(nums, numsSize, i + 1, target);
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
			{
				++j;
				while (j < k && nums[j] == nums[j - 1])
					++j;
			}
			else
				--k;
		}
	}
	return res;
}