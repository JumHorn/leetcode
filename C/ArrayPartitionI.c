#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

int arrayPairSum(int *nums, int numsSize)
{
	qsort(nums, numsSize, sizeof(int), cmp);
	int sum = 0;
	for (int i = 0; i < numsSize; i += 2)
		sum += nums[i];
	return sum;
}
