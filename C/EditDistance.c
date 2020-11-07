#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))
#define trimin(a, b, c) (min(min(a, b), c)) //the minimum of a,b,c

int minDistance(char *word1, char *word2)
{
	int N1 = strlen(word1), N2 = strlen(word2);
	int dp[N1 + 1][N2 + 1];
	dp[0][0] = 0;
	for (int i = 0; i < N1; ++i)
		dp[i + 1][0] = dp[i][0] + 1;
	for (int j = 0; j < N2; ++j)
		dp[0][j + 1] = dp[0][j] + 1;
	for (int i = 0; i < N1; ++i)
	{
		for (int j = 0; j < N2; ++j)
		{
			if (word1[i] == word2[j])
				dp[i + 1][j + 1] = dp[i][j];
			else
				dp[i + 1][j + 1] = trimin(dp[i][j], dp[i + 1][j], dp[i][j + 1]) + 1;
		}
	}
	return dp[N1][N2];
}