#include <math.h>
#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(int n, int* returnSize)
{
	*returnSize = pow(2, n);
	int* res = (int*)malloc(sizeof(int) * (*returnSize));
	memset(res, 0, sizeof(int) * (*returnSize));
	for (int i = 0, size = 1; i < n; ++i)
	{
		for (int j = size - 1; j >= 0; --j)
			res[size++] = res[j] | (1 << i);
	}
	return res;
}
