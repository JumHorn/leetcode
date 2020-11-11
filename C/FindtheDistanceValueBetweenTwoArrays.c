#include <stdlib.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

int findTheDistanceValue(int *arr1, int arr1Size, int *arr2, int arr2Size, int d)
{
	qsort(arr1, arr1Size, sizeof(int), cmp);
	qsort(arr2, arr2Size, sizeof(int), cmp);
	int res = 0;
	for (int i = 0, j = 0; i < arr1Size; ++i)
	{
		while (j < arr2Size && arr2[j] <= arr1[i])
			++j;
		if ((j == arr2Size || arr2[j] - arr1[i] > d) &&
			(j == 0 || arr1[i] - arr2[j - 1] > d))
			++res;
	}
	return res;
}