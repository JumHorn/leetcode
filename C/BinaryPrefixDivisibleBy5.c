#include <stdbool.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool *prefixesDivBy5(int *A, int ASize, int *returnSize)
{
	*returnSize = ASize;
	bool *res = (bool *)malloc(sizeof(bool) * (*returnSize));
	int remainder = 0;
	for (int i = 0; i < ASize; ++i)
	{
		remainder = ((remainder << 1) | A[i]) % 5;
		res[i] = (remainder == 0);
	}
	return res;
}