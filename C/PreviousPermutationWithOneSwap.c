#include <stdlib.h>
#include <string.h>

#define swap(a, b) ((a) ^= (b) ^= (a) ^= (b))

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *prevPermOpt1(int *A, int ASize, int *returnSize)
{
	for (int i = ASize - 1; i > 0; --i)
	{
		if (A[i] < A[i - 1])
		{
			int lo = i, hi = ASize;
			while (lo < hi)
			{
				int mi = (hi - lo) / 2 + lo;
				if (A[mi] < A[i - 1])
					lo = mi + 1;
				else
					hi = mi;
			}
			swap(A[i - 1], A[lo - 1]);
			break;
		}
	}
	*returnSize = ASize;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	memcpy(res, A, sizeof(int) * (*returnSize));
	return res;
}