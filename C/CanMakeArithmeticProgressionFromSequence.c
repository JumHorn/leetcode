#include <stdbool.h>
#include <stdlib.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
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