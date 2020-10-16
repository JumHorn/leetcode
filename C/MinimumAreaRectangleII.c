#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	int *l = *(int **)lhs, *r = *(int **)rhs;
	if (l[0] != r[0])
		return l[0] - r[0];
	return l[1] - r[1];
}

bool binarySeach(int **points, int pointsSize, int x, int y)
{
	int lo = 0, hi = pointsSize - 1;
	while (lo <= hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (points[mi][0] < x)
			lo = mi + 1;
		else if (points[mi][0] > x)
			hi = mi - 1;
		else //points[mi][0] == x
		{
			if (points[mi][1] < y)
				lo = mi + 1;
			else if (points[mi][1] > y)
				hi = mi - 1;
			else //points[mi][1] == y
				return true;
		}
	}
	return false;
}

double minAreaFreeRect(int **points, int pointsSize, int *pointsColSize)
{
	qsort(points, pointsSize, sizeof(int *), cmp);
	double res = INT_MAX;
	for (int i = 0; i < pointsSize; ++i)
	{
		for (int j = 0; j < pointsSize; ++j)
		{
			if (i == j)
				continue;
			for (int k = 0; k < pointsSize; ++k)
			{
				if (i == k || j == k)
					continue;
				int x = points[j][0] + points[k][0] - points[i][0];
				int y = points[j][1] + points[k][1] - points[i][1];
				if (binarySeach(points, pointsSize, x, y))
				{
					//vector dot product
					int tmp = (points[j][0] - points[i][0]) * (points[k][0] - points[i][0]) +
							  (points[j][1] - points[i][1]) * (points[k][1] - points[i][1]);
					if (tmp == 0)
					{
						//vector cross product
						//get area of rectangle(shoelance formula)
						double area = 1.0 * points[i][0] * points[j][1] + points[j][0] * y +
									  x * points[k][1] + points[k][0] * points[i][1] -
									  points[j][0] * points[i][1] - x * points[j][1] -
									  points[k][0] * y - points[i][0] * points[k][1];
						if (area < 0)
							area = -area;
						res = min(res, area / 2.0);
					}
				}
			}
		}
	}
	return res == INT_MAX ? 0 : res;
}