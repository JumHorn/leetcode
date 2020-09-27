#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return (*(int **)lhs)[1] - (*(int **)rhs)[1];
}

int findMinArrowShots(int **points, int pointsSize, int *pointsColSize)
{
	if (pointsSize == 0)
		return 0;
	qsort(points, pointsSize, sizeof(int *), cmp);
	int res = 1, maxright = points[0][1];
	for (int i = 0; i < pointsSize; ++i)
	{
		if (points[i][0] > maxright)
		{
			++res;
			maxright = points[i][1];
		}
	}
	return res;
}
