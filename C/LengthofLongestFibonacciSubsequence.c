#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int lenLongestFibSubseq(int* A, int ASize)
{
	int dp[ASize][ASize], res = 0;
	memset(dp, 0, sizeof(dp));
	for (int i = 2; i < ASize; ++i)
	{
		int l = 0, r = i - 1;
		while (l < r)
		{
			int sum = A[l] + A[r];
			if (sum == A[i])
			{
				dp[i][r] = dp[r][l] + 1;
				res = max(res, dp[i][r]);
				++l;
			}
			else if (sum < A[i])
				++l;
			else
				--r;
		}
	}
	return res == 0 ? 0 : res + 2;
}
