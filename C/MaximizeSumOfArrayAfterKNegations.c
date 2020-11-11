#include <limits.h>
#include <stdlib.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
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