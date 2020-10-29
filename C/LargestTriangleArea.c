#include <math.h>

double triangleArea(int *p1, int *p2, int *p3)
{
	return 0.5 * abs(p1[0] * p2[1] + p2[0] * p3[1] +
					 p3[0] * p1[1] - p1[1] * p2[0] -
					 p2[1] * p3[0] - p3[1] * p1[0]);
}

double largestTriangleArea(int **points, int pointsSize, int *pointsColSize)
{
	double res = 0.0;
	for (int i = 0; i < pointsSize - 2; ++i)
	{
		for (int j = i + 1; j < pointsSize - 1; ++j)
		{
			for (int k = j + 1; k < pointsSize; ++k)
			{
				double area = triangleArea(points[i], points[j], points[k]);
				if (area > res)
					res = area;
			}
		}
	}
	return res;
}