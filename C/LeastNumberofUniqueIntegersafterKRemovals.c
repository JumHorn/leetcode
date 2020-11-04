#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

int findLeastNumOfUniqueInts(int *arr, int arrSize, int k)
{
	int count[arrSize], countSize = 0;
	qsort(arr, arrSize, sizeof(int), cmp);
	for (int i = 1, j = 0; i <= arrSize; ++i)
	{
		if (i == arrSize || arr[i] != arr[j])
		{
			count[countSize++] = i - j;
			j = i;
		}
	}
	int res = countSize;
	qsort(count, countSize, sizeof(int), cmp);
	for (int i = 0; i < countSize && count[i] <= k; ++i)
	{
		--res;
		k -= count[i];
	}
	return res;
}
