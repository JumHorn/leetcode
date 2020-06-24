#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void* lhs, const void* rhs)
{
	return *(int*)lhs - *(int*)rhs;
}

int smallestDistancePair(int* nums, int numsSize, int k)
{
	qsort(nums, numsSize, sizeof(int), cmp);
	int hi = nums[numsSize - 1] - nums[0], lo = 0;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo, count = 0;
		for (int i = 0, j = 0; i < numsSize; i++)
		{
			while (nums[i] - nums[j] > mi)
				++j;
			count += i - j;
		}

		if (count < k)
			lo = mi + 1;
		else
			hi = mi;
	}
	return lo;
}
