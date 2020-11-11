#include <stdlib.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
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