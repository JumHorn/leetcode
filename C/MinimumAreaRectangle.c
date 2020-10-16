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

int minAreaRect(int **points, int pointsSize, int *pointsColSize)
{
	qsort(points, pointsSize, sizeof(int *), cmp);
	int res = INT_MAX;
	for (int i = 0; i < pointsSize - 1; ++i)
	{
		int x1 = points[i][0], y1 = points[i][1];
		for (int j = i + 1; j < pointsSize; ++j)
		{
			int x2 = points[j][0], y2 = points[j][1];
			if (x2 > x1 && y2 > y1)
			{
				if (binarySeach(points, pointsSize, x1, y2) &&
					binarySeach(points, pointsSize, x2, y1))
					res = min(res, (x2 - x1) * (y2 - y1));
			}
		}
	}
	return res == INT_MAX ? 0 : res;
}