#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

int numSubseq(int *nums, int numsSize, int target)
{
	static const int MOD = 1e9 + 7;
	qsort(nums, numsSize, sizeof(int), cmp);
	long res = 0;
	long pow2[numsSize + 1];
	pow2[0] = 1;
	for (int i = 0; i < numsSize; ++i)
		pow2[i + 1] = pow2[i] * 2 % MOD;
	for (int i = 0, j = numsSize - 1; i <= j;)
	{
		if (nums[i] + nums[j] > target)
			--j;
		else
			res = (res + pow2[j - i++]) % MOD;
	}
	return res;
}
