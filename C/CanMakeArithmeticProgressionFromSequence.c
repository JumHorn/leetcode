#include <stdbool.h>
#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

bool canMakeArithmeticProgression(int *arr, int arrSize)
{
	qsort(arr, arrSize, sizeof(int), cmp);
	int gap = arr[1] - arr[0];
	for (int i = 2; i < arrSize; ++i)
	{
		if (gap != arr[i] - arr[i - 1])
			return false;
	}
	return true;
}
