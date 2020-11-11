#include <stdbool.h>
#include <stdlib.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

bool canBeEqual(int *target, int targetSize, int *arr, int arrSize)
{
	if (arrSize != targetSize)
		return false;
	qsort(arr, arrSize, sizeof(int), cmp);
	qsort(target, targetSize, sizeof(int), cmp);
	for (int i = 0; i < arrSize; ++i)
	{
		if (arr[i] != target[i])
			return false;
	}
	return true;
}