#include <stdlib.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int minTimeToVisitAllPoints(int **points, int pointsSize, int *pointsColSize)
{
	int res = 0;
	for (int i = 1; i < pointsSize; ++i)
	{
		int a = abs(points[i][0] - points[i - 1][0]), b = abs(points[i][1] - points[i - 1][1]);
		res += min(a, b) + abs(a - b);
	}
	return res;
}