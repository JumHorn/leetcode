#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int longestCommonSubsequence(char* text1, char* text2)
{
	int N1 = strlen(text1), N2 = strlen(text2);
	int dp[N1 + 1][N2 + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < N1; ++i)
	{
		for (int j = 0; j < N2; ++j)
		{
			if (text1[i] == text2[j])
				dp[i + 1][j + 1] = 1 + dp[i][j];
			else
				dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
		}
	}
	return dp[N1][N2];
}
