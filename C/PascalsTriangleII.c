#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *getRow(int rowIndex, int *returnSize)
{
	*returnSize = rowIndex + 1;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	res[0] = 1;
	for (int i = 1; i <= rowIndex; ++i)
	{
		res[0] = res[i] = 1;
		for (int j = i - 1; j > 0; --j)
			res[j] += res[j - 1];
	}
	return res;
}