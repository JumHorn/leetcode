#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructArray(int n, int k, int* returnSize)
{
	*returnSize = n;
	int *res = (int*)malloc(sizeof(int) * (*returnSize)), index = 0;
	for (int i = 1; i < n - k; ++i)
		res[index++] = i;
	for (int i = 0; i <= k; ++i)
		res[index++] = (i % 2 == 0) ? (n - k + i / 2) : (n - i / 2);
	return res;
}
