#include <math.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructRectangle(int area, int* returnSize)
{
	*returnSize = 2;
	int* res = (int*)malloc(sizeof(int) * (*returnSize));
	for (int i = sqrt(area); i >= 1; --i)
	{
		if (area % i == 0)
		{
			res[0] = area / i;
			res[1] = i;
			break;
		}
	}
	return res;
}
