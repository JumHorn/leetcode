#include <stdlib.h>

int cmp(const void* lhs, const void* rhs)
{
	return *(int*)lhs - *(int*)rhs;
}

int smallestRangeII(int* A, int ASize, int K)
{
	qsort(A, ASize, sizeof(int), cmp);
	int res = A[ASize - 1] - A[0], max, min;
	for (int i = 0; i < ASize - 1; i++)
	{
		max = A[ASize - 1] - K;
		if (A[i] + K > max)
			max = A[i] + K;
		min = A[0] + K;
		if (A[i + 1] - K < min)
			min = A[i + 1] - K;
		if (max - min < res)
			res = max - min;
	}
	return res;
}
