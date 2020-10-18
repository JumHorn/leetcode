#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int longestArithSeqLength(int* A, int ASize)
{
	int res = 0, dp[ASize][1001];  //{diff,length}
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < ASize; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			int diff = A[i] - A[j] + 500;
			dp[i][diff] = max(dp[j][diff] + 1, 2);
			res = max(res, dp[i][diff]);
		}
	}
	return res;
}
