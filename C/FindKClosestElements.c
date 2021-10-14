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
int *findClosestElements(int *arr, int arrSize, int k, int x, int *returnSize)
{
	*returnSize = k;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	int lo = 0, hi = arrSize;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (arr[mi] < x)
			lo = mi + 1;
		else
			hi = mi;
	}
	--lo;
	while (k > 0 && lo >= 0 && hi < arrSize)
	{
		if (abs(arr[lo] - x) <= abs(arr[hi] - x))
		{
			res[--k] = arr[lo];
			--lo;
		}
		else
		{
			res[--k] = arr[hi];
			++hi;
		}
	}
	for (; k > 0 && lo >= 0; --lo)
		res[--k] = arr[lo];
	for (; k > 0 && hi < arrSize; ++hi)
		res[--k] = arr[hi];
	qsort(res, *returnSize, sizeof(int), cmp);
	return res;
}
