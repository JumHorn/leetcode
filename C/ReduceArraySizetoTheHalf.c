#include <stdlib.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
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