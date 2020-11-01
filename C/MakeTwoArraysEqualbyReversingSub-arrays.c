#include <stdbool.h>
#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
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
