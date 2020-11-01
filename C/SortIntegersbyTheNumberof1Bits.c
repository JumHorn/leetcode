#include <stdlib.h>

int bitCount(int n)
{
	int res = 0;
	for (; n != 0; n &= n - 1)
		++res;
	return res;
}

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	int a = bitCount(*(int *)lhs), b = bitCount(*(int *)rhs);
	if (a != b)
		return a - b;
	return *(int *)lhs - *(int *)rhs;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortByBits(int *arr, int arrSize, int *returnSize)
{
	*returnSize = arrSize;
	qsort(arr, arrSize, sizeof(int), cmp);
	return arr;
}
