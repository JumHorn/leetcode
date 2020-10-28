#include <math.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* closestDivisors(int num, int* returnSize)
{
	*returnSize = 2;
	int* res = (int*)malloc(sizeof(int) * (*returnSize));
	for (int i = sqrt(num + 2); i >= 1; --i)
	{
		if ((num + 1) % i == 0)
		{
			res[0] = i;
			res[1] = (num + 1) / i;
			break;
		}
		if ((num + 2) % i == 0)
		{
			res[0] = i;
			res[1] = (num + 2) / i;
			break;
		}
	}
	return res;
}
