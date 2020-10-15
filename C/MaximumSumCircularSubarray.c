#include <limits.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxSubarraySumCircular(int *A, int ASize)
{
	int suffixsum = 0, maxright[ASize + 1];
	maxright[ASize] = 0;
	for (int i = ASize - 1; i >= 0; --i)
	{
		suffixsum += A[i];
		maxright[i] = max(maxright[i + 1], suffixsum);
	}

	int dp = 0, prefixsum = 0, res = INT_MIN, maxleft = res;
	for (int i = 0; i < ASize; ++i)
	{
		prefixsum += A[i];
		dp = max(dp, 0) + A[i];
		res = max(res, dp);

		maxleft = max(maxleft, prefixsum);
		res = max(res, maxleft + maxright[i + 1]);
	}
	return res;
}