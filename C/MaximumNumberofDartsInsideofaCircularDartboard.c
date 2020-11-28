#include <math.h>
#include <stdbool.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

typedef struct Point
{
	double x;
	double y;
} Point;

typedef struct pair
{
	Point first;
	Point second;
} pair;

static const double PRECIOUSE = 1e-5;

bool isInCircle(Point *c, int *p, int R)
{
	return (c->x - p[0]) * (c->x - p[0]) + (c->y - p[1]) * (c->y - p[1]) - R * R <= PRECIOUSE;
}

pair getCircleCenter(int *A, int *B, int R)
{
	double midx = (A[0] + B[0]) / 2.0, midy = (A[1] + B[1]) / 2.0;
	double val = hypot(midx - A[0], midy - A[1]);
	double d = sqrt(R * R - val * val);
	double theta = atan2(A[1] - B[1], A[0] - B[0]);
	pair res;
	res.first.x = midx - d * sin(theta);
	res.first.y = midy + d * cos(theta);
	res.second.x = midx + d * sin(theta);
	res.second.y = midy - d * cos(theta);
	return res;
}

int numPoints(int **points, int pointsSize, int *pointsColSize, int r)
{
	int res = 1, N = pointsSize;
	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			if (hypot(points[i][0] - points[j][0], points[i][1] - points[j][1]) - 2 * r > PRECIOUSE)
				continue;
			//calc two circle center
			pair center = getCircleCenter(points[i], points[j], r);
			int a = 0, b = 0;
			for (int k = 0; k < N; ++k)
			{
				if (isInCircle(&center.first, points[k], r))
					++a;
				if (isInCircle(&center.second, points[k], r))
					++b;
			}
			res = max(res, a);
			res = max(res, b);
		}
	}
	return res;
}