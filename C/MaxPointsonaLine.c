/*
向量叉乘，面积为0，即可判断三点共线
*/

// cross product
long crossProduct(int *pointA, int *pointB, int *pointC)
{
	long x1 = pointB[0] - pointA[0];
	long y1 = pointB[1] - pointA[1];
	long x2 = pointC[0] - pointA[0];
	long y2 = pointC[1] - pointA[1];
	return x1 * y2 - x2 * y1;
}
/********end of cross product********/

int maxPoints(int **points, int pointsSize, int *pointsColSize)
{
	if (pointsSize <= 2)
		return pointsSize;
	int res = 2;
	for (int i = 0; i < pointsSize - 1; ++i)
	{
		int duplicate = 1;
		for (int j = i + 1; j < pointsSize; ++j)
		{
			if (points[i][0] == points[j][0] && points[i][1] == points[j][1])
			{
				++duplicate;
				continue;
			}
			int localmax = 0;
			for (int k = 0; k < pointsSize; ++k)
			{
				//向量ik X ij
				if (crossProduct(points[k], points[i], points[j]) == 0)
					++localmax;
			}
			if (res < localmax)
				res = localmax;
		}
		if (res < duplicate)
			res = duplicate;
	}
	return res;
}