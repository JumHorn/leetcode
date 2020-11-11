#include <stdlib.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
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