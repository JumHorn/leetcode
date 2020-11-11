#include <stdlib.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

int binarySearch(int (*hash)[2], int size, int val)
{
	int lo = 0, hi = size;
	if (val > hash[size - 1][0])
		return -1;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (hash[mi][0] < val)
			lo = mi + 1;
		else
			hi = mi;
	}
	return lo == size ? -1 : hash[lo][1];
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *findRightInterval(int **intervals, int intervalsSize, int *intervalsColSize, int *returnSize)
{
	if (intervalsSize == 0)
	{
		*returnSize = 0;
		return NULL;
	}
	int hash[intervalsSize][2]; //{intervals start,index}
	for (int i = 0; i < intervalsSize; ++i)
	{
		hash[i][0] = intervals[i][0];
		hash[i][1] = i;
	}
	qsort(hash, intervalsSize, sizeof(hash[0]), cmp);
	*returnSize = intervalsSize;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	for (int i = 0; i < intervalsSize; ++i)
		res[i] = binarySearch(hash, intervalsSize, intervals[i][1]);
	return res;
}