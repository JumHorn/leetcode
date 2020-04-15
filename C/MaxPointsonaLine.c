/*
向量叉乘，面积为0，即可判断三点共线
*/

int maxPoints(int **points, int pointsSize, int *pointsColSize)
{
	if (pointsSize <= 2)
		return pointsSize;
	int res = 2;
	for (int i = 0; i < pointsSize - 1; i++)
	{
		int duplicate = 1;
		for (int j = i + 1; j < pointsSize; j++)
		{
			if (points[i][0] == points[j][0] && points[i][1] == points[j][1])
			{
				++duplicate;
				continue;
			}
			int localmax = 0;
			for (int k = 0; k < pointsSize; k++)
			{
				//向量ik X ij
				long x1 = points[k][0] - points[i][0];
				long x2 = points[k][0] - points[j][0];
				long y1 = points[k][1] - points[i][1];
				long y2 = points[k][1] - points[j][1];
				if (x1 * y2 - y1 * x2 == 0)
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