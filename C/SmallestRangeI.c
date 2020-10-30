#include <limits.h>

int smallestRangeI(int *A, int ASize, int K)
{
	int max = A[0], min = A[0];
	for (int i = 0; i < ASize; ++i)
	{
		if (A[i] > max)
			max = A[i];
		else if (A[i] < min)
			min = A[i];
	}
	int res = max - min - K * 2;
	return res < 0 ? 0 : res;
}