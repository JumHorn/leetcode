#include <math.h>

#define PI (3.141592653)
#define max(a, b) (((a) > (b)) ? (a) : (b))

//cmp function don't consider overflow
int cmp(const void* lhs, const void* rhs)
{
	if (*(double*)lhs == *(double*)rhs)
		return 0;
	return *(double*)lhs - *(double*)rhs > 0 ? 1 : -1;
}

double angleToAxis(int* point)
{
	return atan2(point[1], point[0]);
}

int visiblePoints(int** points, int pointsSize, int* pointsColSize, int angle, int* location, int locationSize)
{
	double ang = angle / 180.0 * PI;
	double p[pointsSize * 2];
	int repeat_location = 0, psize = 0;
	for (int i = 0; i < pointsSize; ++i)
	{
		points[i][0] -= location[0];
		points[i][1] -= location[1];
		if (points[i][0] == 0 && points[i][1] == 0)
			++repeat_location;
		else
			p[psize++] = angleToAxis(points[i]);
	}
	qsort(p, psize, sizeof(double), cmp);
	int res = 0;
	for (int i = 0; i < psize; ++i)
		p[psize + i] = p[i] + 2 * PI;
	for (int i = 0, j = 0; i < 2 * psize; ++i)
	{
		while (i < 2 * psize && p[i] - p[j] <= ang)
			++i;
		res = max(res, i - j);
		++j;
	}
	return res + repeat_location;
}
