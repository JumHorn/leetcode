#include <stdlib.h>

/*
gray code
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* circularPermutation(int n, int start, int* returnSize)
{
	*returnSize = (1 << n);
	int* res = (int*)malloc(sizeof(int) * (*returnSize));
	for (int i = 0; i < (1 << n); ++i)
		res[i] = start ^ i ^ (i >> 1);
	return res;
}
