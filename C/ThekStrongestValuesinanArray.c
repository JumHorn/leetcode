#include <stdlib.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *getStrongest(int *arr, int arrSize, int k, int *returnSize)
{
	qsort(arr, arrSize, sizeof(int), cmp);
	int i = 0, j = arrSize - 1;
	int median = arr[(arrSize - 1) / 2];
	while (--k >= 0)
	{
		if (median - arr[i] > arr[j] - median)
			++i;
		else
			--j;
	}
	for (++j; j < arrSize; ++i, ++j)
		arr[i] = arr[j];
	*returnSize = i;
	return arr;
}