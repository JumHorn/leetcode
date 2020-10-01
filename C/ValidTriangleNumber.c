#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

int triangleNumber(int *nums, int numsSize)
{
	qsort(nums, numsSize, sizeof(int), cmp);
	int res = 0, N = numsSize;
	for (int i = 0; i < N - 2; ++i)
	{
		for (int j = i + 1; j < N - 1; ++j)
		{
			int lo = j + 1, hi = N;
			while (lo < hi)
			{
				int mi = (hi - lo) / 2 + lo;
				if (nums[mi] < nums[i] + nums[j])
					lo = mi + 1;
				else
					hi = mi;
			}
			res += lo - j - 1;
		}
	}
	return res;
}
