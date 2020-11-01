#include <stdlib.h>

int bitCount(int n)
{
	int res = 0;
	for (; n != 0; n &= n - 1)
		++res;
	return res;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *countBits(int num, int *returnSize)
{
	*returnSize = num + 1;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	for (int i = 0; i <= num; ++i)
		res[i] = bitCount(i);
	return res;
}