#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int minDifficulty(int *jobDifficulty, int jobDifficultySize, int d)
{
	int N = jobDifficultySize;
	int dp[N + 1][d + 1];
	memset(dp, 1 << 6, sizeof(dp));
	dp[0][0] = 0;
	for (int i = 0; i < N; ++i)
	{
		int most = jobDifficulty[i];
		for (int j = i; j >= 0; --j)
		{
			most = max(most, jobDifficulty[j]);
			for (int k = 0; k < d && k <= j; ++k)
				dp[i + 1][k + 1] = min(dp[i + 1][k + 1], dp[j][k] + most);
		}
	}
	return dp[N][d] >= 1e5 ? -1 : dp[N][d];
}