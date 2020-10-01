#include <stdbool.h>
#include <string.h>

int countSubstrings(char* s)
{
	int N = strlen(s), res = N;
	bool dp[N][N];
	memset(dp, 0, sizeof(dp));
	for (int i = N - 1; i >= 0; --i)
	{
		dp[i][i] = true;
		for (int j = i + 1; j < N; ++j)
		{
			if (s[i] == s[j] && (j - i == 1 || dp[i + 1][j - 1]))
			{
				dp[i][j] = true;
				++res;
			}
		}
	}
	return res;
}
