#include <limits.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxRotateFunction(int* A, int ASize)
{
	if (ASize == 0)
		return 0;
	long sum = 0, pre = 0, res = INT_MIN;
	for (int i = 0; i < ASize; ++i)
	{
		pre += (long)i * A[i];
		sum += A[i];
	}
	for (int i = ASize - 1; i >= 0; --i)
	{
		pre = pre + sum - (long)ASize * A[i];
		res = max(res, pre);
	}
	return res;
}
