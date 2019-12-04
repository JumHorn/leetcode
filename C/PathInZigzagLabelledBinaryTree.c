#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pathInZigZagTree(int label, int* returnSize)
{
	int bin[21] = {1 << 0, 1 << 1, 1 << 2, 1 << 3, 1 << 4, 1 << 5, 1 << 6, 1 << 7, 1 << 8, 1 << 9, 1 << 10, 1 << 11, 1 << 12, 1 << 13, 1 << 14, 1 << 15, 1 << 16, 1 << 17, 1 << 18, 1 << 19, 1 << 20};
	int lo = 0, hi = 20, mi;
	while (lo < hi)
	{
		mi = (hi - lo) / 2 + lo;
		if (bin[mi] == label)
		{
			lo = mi + 1;
			break;
		}
		if (bin[mi] < label)
			lo = mi + 1;
		else
			hi = mi;
	}
	int n = lo;
	*returnSize = n;
	int* res = (int*)malloc(sizeof(int) * n);
	while (n > 0)
	{
		res[--n] = label;
		label = 3 * bin[n] - 1 - label;
		label /= 2;
	}
	return res;
}

