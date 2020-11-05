#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
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
