#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *pathInZigZagTree(int label, int *returnSize)
{
	int pow2[21];
	for (int i = 0; i < 21; ++i)
		pow2[i] = (1 << i);
	int lo = 0, hi = 20;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (pow2[mi] <= label)
			lo = mi + 1;
		else
			hi = mi;
	}
	*returnSize = lo;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	for (int i = *returnSize - 1; i >= 0; --i)
	{
		res[i] = label;
		label = 3 * pow2[i] - 1 - label;
		label /= 2;
	}
	return res;
}