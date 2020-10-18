#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxUncrossedLines(int* A, int ASize, int* B, int BSize)
{
	int dp[ASize + 1][BSize + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < ASize; ++i)
	{
		for (int j = 0; j < BSize; ++j)
		{
			if (A[i] == B[j])
				dp[i + 1][j + 1] = dp[i][j] + 1;
			else
				dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
		}
	}
	return dp[ASize][BSize];
}
