#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
/*
Algorithm
Y axis line scan
*/

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return **(int **)lhs - **(int **)rhs;
}

int rectangleArea(int **rectangles, int rectanglesSize, int *rectanglesColSize)
{
	static const int MOD = 1e9 + 7;
	unsigned long long res = 0, y = 0;
	qsort(rectangles, rectanglesSize, sizeof(int *), cmp);
	while (y != INT_MAX)
	{
		bool flag = false;
		unsigned long long x = 0, xlen = 0, ystep = INT_MAX;
		for (int i = 0; i < rectanglesSize; ++i)
		{
			if (rectangles[i][1] > (int)y)
				ystep = min((int)ystep, rectangles[i][1]);
			if ((int)y >= rectangles[i][1] && (int)y < rectangles[i][3] && rectangles[i][2] > (int)x)
			{
				flag = true;
				x = max((int)x, rectangles[i][0]);
				ystep = min((int)ystep, rectangles[i][3]);
				xlen += rectangles[i][2] - x;
				x = rectangles[i][2];
			}
		}
		if (flag)
			res += xlen * (ystep - y);
		y = ystep;
	}
	return res % MOD;
}