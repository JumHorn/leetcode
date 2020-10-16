#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

int minIncrementForUnique(int *A, int ASize)
{
	qsort(A, ASize, sizeof(int), cmp);
	int res = 0;
	for (int i = 1; i < ASize; ++i)
	{
		if (A[i] <= A[i - 1])
		{
			res += A[i - 1] + 1 - A[i];
			A[i] = A[i - 1] + 1;
		}
	}
	return res;
}
