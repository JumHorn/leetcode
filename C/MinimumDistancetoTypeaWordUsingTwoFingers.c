#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int distance(int pos1, int pos2)
{
	return abs(pos1 % 6 - pos2 % 6) + abs(pos1 / 6 - pos2 / 6);
}

int minimumDistance(char *word)
{
	int N = strlen(word);
	int dp[N + 1][26][26];
	memset(dp, 1 << 6, sizeof(dp));
	memset(dp[0], 0, sizeof(dp[0]));
	for (int k = 0; k < N; ++k)
	{
		for (int i = 0; i < 26; ++i)
		{
			for (int j = 0; j < 26; ++j)
			{
				int w = word[k] - 'A';
				dp[k + 1][w][j] = min(dp[k + 1][w][j], dp[k][i][j] + distance(i, w));
				dp[k + 1][i][w] = min(dp[k + 1][i][w], dp[k][i][j] + distance(j, w));
			}
		}
	}
	int res = INT_MAX;
	for (int i = 0; i < 26; ++i)
	{
		for (int j = 0; j < 26; ++j)
			res = min(res, dp[N][i][j]);
	}
	return res;
}