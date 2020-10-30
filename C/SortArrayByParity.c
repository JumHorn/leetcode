#include <stdlib.h>

void swap(int* lhs, int* rhs)
{
	int tmp = *lhs;
	*lhs = *rhs;
	*rhs = tmp;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArrayByParity(int* A, int ASize, int* returnSize)
{
	*returnSize = ASize;
	int i = 0, j = ASize - 1;
	while (i < j)
	{
		if ((A[i] & 1) == 0)
			++i;
		else if ((A[j] & 1) == 1)
			--j;
		else
			swap(&A[i++], &A[j--]);
	}
	return A;
}
