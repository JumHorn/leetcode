#include <stdlib.h>
#include <string.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(long *)lhs - *(long *)rhs;
}

long distance(int *p1, int *p2)
{
	return (long)(p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
}

int numberOfBoomerangs(int **points, int pointsSize, int *pointsColSize)
{
	int res = 0, arrSize = 0;
	long arr[pointsSize * pointsSize];
	for (int i = 0; i < pointsSize; ++i)
	{
		for (int j = 0; j < pointsSize; ++j)
		{
			if (i != j)
				arr[arrSize++] = distance(points[i], points[j]);
		}
		qsort(arr, arrSize, sizeof(long), cmp);
		for (int i = 1, j = 0; i <= arrSize; ++i)
		{
			if (i == arrSize || arr[i] != arr[j])
			{
				res += (i - j) * (i - j - 1);
				j = i;
			}
		}
		arrSize = 0;
	}
	return res;
}