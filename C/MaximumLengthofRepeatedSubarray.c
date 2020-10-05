#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int findLength(int* A, int ASize, int* B, int BSize)
{
	int dp[ASize + 1][BSize + 1];
	memset(dp, 0, sizeof(dp));
	int res = 0;
	for (int i = 0; i < ASize; ++i)
	{
		for (int j = 0; j < BSize; ++j)
		{
			if (A[i] == B[j])
				dp[i + 1][j + 1] = dp[i][j] + 1;
			res = max(res, dp[i + 1][j + 1]);
		}
	}
	return res;
}
