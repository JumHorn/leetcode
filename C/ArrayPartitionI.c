#include <stdlib.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

int arrayPairSum(int *nums, int numsSize)
{
	qsort(nums, numsSize, sizeof(int), cmp);
	int sum = 0;
	for (int i = 0; i < numsSize; i += 2)
		sum += nums[i];
	return sum;
}