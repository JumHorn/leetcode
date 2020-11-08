#include <stdbool.h>
#include <string.h>

/*
dp[i][j][N] whether [i,i+N) and [j,j+N) is scramble
*/

bool isScramble(char *s1, char *s2)
{
	int N = strlen(s1);
	if (N == 0)
		return true;
	bool dp[N][N][N + 1];
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			dp[i][j][1] = (s1[i] == s2[j]);
	}
	for (int l = 2; l <= N; ++l)
	{
		for (int i = 0; i <= N - l; ++i)
		{
			for (int j = 0; j <= N - l; ++j)
			{
				dp[i][j][l] = false;
				for (int k = 1; k < l && !dp[i][j][l]; ++k)
					dp[i][j][l] = ((dp[i][j][k] && dp[i + k][j + k][l - k]) ||
								   (dp[i + l - k][j][k] && dp[i][j + k][l - k]));
			}
		}
	}
	return dp[0][0][N];
}