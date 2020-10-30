#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *sortedSquares(int *A, int ASize, int *returnSize)
{
	*returnSize = ASize;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	int i = 0, j = ASize - 1;
	for (int k = ASize - 1; k >= 0; --k)
	{
		if (abs(A[i]) > abs(A[j]))
		{
			res[k] = A[i] * A[i];
			++i;
		}
		else
		{
			res[k] = A[j] * A[j];
			--j;
		}
	}
	return res;
}