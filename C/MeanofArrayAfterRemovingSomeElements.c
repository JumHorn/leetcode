#include <stdlib.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

double trimMean(int *arr, int arrSize)
{
	qsort(arr, arrSize, sizeof(int), cmp);
	int N = arrSize, sum = 0;
	for (int i = N * 0.05; i < N - 0.05 * N; ++i)
		sum += arr[i];
	return sum * 1.0 / (N - 0.1 * N);
}
