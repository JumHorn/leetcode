#include <stdlib.h>
#include <string.h>

/*
// another gray code to decimal always used

int grayCodeToDecimal(int n)
{
	int res = 0;
	for (; n != 0; n >>= 1)
		res ^= n;
	return res;
}
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *grayCode(int n, int *returnSize)
{
	*returnSize = (1 << n);
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	for (int i = 0; i < (1 << n); ++i)
		res[i] = i ^ (i >> 1);
	return res;
}