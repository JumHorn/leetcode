#include <limits.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int minScoreTriangulation(int *A, int ASize)
{
	int dp[ASize][ASize];
	memset(dp, 0, sizeof(dp));
	for (int i = ASize - 3; i >= 0; --i)
	{
		dp[i][i + 2] = A[i] * A[i + 1] * A[i + 2];
		for (int j = i + 3; j < ASize; ++j)
		{
			dp[i][j] = INT_MAX;
			for (int k = i + 1; k < j; ++k)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + A[i] * A[k] * A[j]);
		}
	}
	return dp[0][ASize - 1];
}