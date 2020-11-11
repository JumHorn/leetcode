#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

int maxWidthOfVerticalArea(int **points, int pointsSize, int *pointsColSize)
{
	int arr[2 * pointsSize], arrSize = 0;
	for (int i = 0; i < pointsSize; ++i)
		arr[arrSize++] = points[i][0];
	qsort(arr, arrSize, sizeof(int), cmp);
	int res = 0;
	for (int i = 1; i < arrSize; ++i)
	{
		if (arr[i] - arr[i - 1] != 0)
			res = max(res, arr[i] - arr[i - 1]);
	}
	return res;
}