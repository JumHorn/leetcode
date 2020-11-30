#include <string.h>

int numWays(char **words, int wordsSize, char *target)
{
	static const int MOD = 1e9 + 7;
	int M = strlen(target), N = strlen(words[0]);
	int word[N][26];
	memset(word, 0, sizeof(word));
	for (int i = 0; i < wordsSize; ++i)
	{
		for (int j = 0; j < N; ++j)
			++word[j][words[i][j] - 'a'];
	}
	long dp[M + 1][N + 1];
	memset(dp, 0, sizeof(dp));
	for (int j = 0; j <= N; ++j)
		dp[0][j] = 1;
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < N; ++j)
			dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i + 1][j] + dp[i][j] * word[j][target[i] - 'a'] % MOD) % MOD;
	}
	return dp[M][N];
}