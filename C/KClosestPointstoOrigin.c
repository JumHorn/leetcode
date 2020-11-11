#include <stdlib.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int **kClosest(int **points, int pointsSize, int *pointsColSize, int K, int *returnSize, int **returnColumnSizes)
{
	int arr[pointsSize][2]; //{distance,index of point}
	for (int i = 0; i < pointsSize; ++i)
	{
		arr[i][0] = points[i][0] * points[i][0] + points[i][1] * points[i][1];
		arr[i][1] = i;
	}
	qsort(arr, pointsSize, sizeof(arr[0]), cmp);

	*returnSize = K;
	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	memcpy(*returnColumnSizes, pointsColSize, sizeof(int) * (*returnSize));
	int **res = (int **)malloc(sizeof(int *) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
	{
		res[i] = (int *)malloc(sizeof(int) * ((*returnColumnSizes)[i]));
		memcpy(res[i], points[arr[i][1]], sizeof(int) * ((*returnColumnSizes)[i]));
	}
	return res;
}