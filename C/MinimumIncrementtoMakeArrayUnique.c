#include <stdlib.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
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