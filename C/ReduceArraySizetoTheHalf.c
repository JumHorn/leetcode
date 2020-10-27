#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)rhs - *(int *)lhs;
}

int minSetSize(int *arr, int arrSize)
{
	int hash[100001] = {0}, res = 0;
	for (int i = 0; i < arrSize; ++i)
		++hash[arr[i]];
	qsort(hash, 100001, sizeof(int), cmp); //descending
	for (int i = 0, count = 0; i < 100001 && 2 * count < arrSize;)
	{
		++res;
		count += hash[i++];
	}
	return res;
}