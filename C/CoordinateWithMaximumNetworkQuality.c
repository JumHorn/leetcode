#include <math.h>
#include <stdlib.h>

int getPostionQuality(int** towers, int towersSize, int x, int y, int radius)
{
	int res = 0;
	for (int i = 0; i < towersSize; ++i)
	{
		double d = sqrt((towers[i][0] - x) * (towers[i][0] - x) + (towers[i][1] - y) * (towers[i][1] - y));
		if (d <= radius)
			res += towers[i][2] / (1 + d);
	}
	return res;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* bestCoordinate(int** towers, int towersSize, int* towersColSize, int radius, int* returnSize)
{
	*returnSize = 2;
	int* res = (int*)malloc(sizeof(int) * (*returnSize));
	int maxquality = -1;
	for (int i = 0; i <= 50; ++i)
	{
		for (int j = 0; j <= 50; ++j)
		{
			int quality = getPostionQuality(towers, towersSize, i, j, radius);
			if (quality > maxquality)
			{
				maxquality = quality;
				res[0] = i;
				res[1] = j;
			}
		}
	}
	return res;
}
