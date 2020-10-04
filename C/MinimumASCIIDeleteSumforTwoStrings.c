#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int minimumDeleteSum(char* s1, char* s2)
{
	int M = strlen(s1), N = strlen(s2);
	int dp[M + 1][N + 1];
	dp[0][0] = 0;
	for (int i = 0; i < M; ++i)
		dp[i + 1][0] = dp[i][0] + s1[i];
	for (int j = 0; j < N; ++j)
		dp[0][j + 1] = dp[0][j] + s2[j];
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (s1[i] == s2[j])
				dp[i + 1][j + 1] = dp[i][j];
			else
				dp[i + 1][j + 1] = min(dp[i + 1][j] + s2[j], dp[i][j + 1] + s1[i]);
		}
	}
	return dp[M][N];
}
