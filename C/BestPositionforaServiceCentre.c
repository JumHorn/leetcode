#include <float.h>
#include <limits.h>
#include <math.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

double getMinDistSum(int **positions, int positionsSize, int *positionsColSize)
{
	double left = 100, bottom = 100, right = 0, top = 0;
	for (int i = 0; i < positionsSize; ++i)
	{
		left = min(left, (double)positions[i][0]);
		bottom = min(bottom, (double)positions[i][1]);
		right = max(right, (double)positions[i][0]);
		top = max(top, (double)positions[i][1]);
	}
	double res = INT_MAX, min_x = 0, min_y = 0;
	for (double delta = 10; delta >= 0.00001; delta /= 10)
	{
		for (double x = left; x <= right; x += delta)
		{
			for (double y = bottom; y <= top; y += delta)
			{
				double d = 0;
				for (int i = 0; i < positionsSize; ++i)
					d += hypot(positions[i][0] - x, positions[i][1] - y);
				if (res > d)
				{
					res = d;
					min_x = x;
					min_y = y;
				}
			}
		}
		left = min_x - delta;
		bottom = min_y - delta;
		right = min_x + delta;
		top = min_y + delta;
	}
	return res >= INT_MAX ? 0 : res;
}