#include <limits.h>
#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

int largestSumAfterKNegations(int *A, int ASize, int K)
{
	qsort(A, ASize, sizeof(int), cmp);
	for (int i = 0; i < ASize && A[i] < 0 && K > 0; ++i, --K)
		A[i] = -A[i];
	K %= 2;
	int res = 0, min = INT_MAX;
	for (int i = 0; i < ASize; ++i)
	{
		res += A[i];
		if (A[i] < min)
			min = A[i];
	}
	return res - (K == 0 ? 0 : 2 * min);
}