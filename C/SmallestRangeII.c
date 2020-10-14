#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return *(int *)lhs - *(int *)rhs;
}

int smallestRangeII(int *A, int ASize, int K)
{
	qsort(A, ASize, sizeof(int), cmp);
	int res = A[ASize - 1] - A[0];
	for (int i = 0; i < ASize - 1; ++i)
	{
		int a = A[i], b = A[i + 1];
		int high = max(A[ASize - 1] - K, a + K);
		int low = min(A[0] + K, b - K);
		res = min(res, high - low);
	}
	return res;
}