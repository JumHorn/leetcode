#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

int specialArray(int *nums, int numsSize)
{
	qsort(nums, numsSize, sizeof(int), cmp);
	int X = 1;
	for (int i = numsSize - 1; i >= 0; --i, ++X)
	{
		if (X > nums[i])
			return -1;
		if (i == 0 || X > nums[i - 1])
			return X;
	}
	return -1;
}
