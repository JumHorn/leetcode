#include <stdlib.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

int largestPerimeter(int *A, int ASize)
{
	qsort((void *)A, ASize, sizeof(int), cmp);
	for (int i = ASize - 1; i >= 2; --i)
	{
		if (A[i] < A[i - 1] + A[i - 2])
			return A[i] + A[i - 1] + A[i - 2];
	}
	return 0;
}