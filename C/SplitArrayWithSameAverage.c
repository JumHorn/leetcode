#include <stdbool.h>
#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

bool backTracking(int *A, int ASize, int index, int count, int subsum, int sum)
{
	if (index >= ASize)
		return false;
	if (count != 0 && subsum * ASize == sum * count)
		return true;
	if (subsum * ASize > sum * count)
		return false;
	if (backTracking(A, ASize, index + 1, count, subsum, sum))
		return true;
	if (backTracking(A, ASize, index + 1, count + 1, subsum + A[index], sum))
		return true;
	return false;
}

bool isPossible(int ASize, int sum)
{
	for (int i = 1; i <= ASize / 2; ++i)
	{
		if (sum * i % ASize == 0)
			return true;
	}
	return false;
}

bool splitArraySameAverage(int *A, int ASize)
{
	qsort(A, ASize, sizeof(int), cmp);
	int sum = 0;
	for (int i = 0; i < ASize; ++i)
		sum += A[i];
	// early pruning
	if (!isPossible(ASize, sum))
		return false;
	return backTracking(A, ASize, 0, 0, 0, sum);
}
