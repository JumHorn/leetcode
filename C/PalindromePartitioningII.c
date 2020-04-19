#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int minCut(char* s)
{
	int n = strlen(s);
	int dp[n][n], cut[n + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < n; i++)
		dp[i][i] = 1;
	for (int i = 0; i < n - 1; i++)
		if (s[i] == s[i + 1])
			dp[i][i + 1] = 1;
	for (int len = 2; len < n; len++)
	{
		for (int i = 0; i < n - len; i++)
		{
			int j = i + len;
			if (s[i] == s[j])
				dp[i][j] = dp[i + 1][j - 1];
		}
	}
	cut[0] = -1;
	for (int i = 0; i < n; i++)
	{
		cut[i + 1] = n;
		for (int j = 0; j <= i; j++)
		{
			if (dp[j][i] == 1)
				cut[i + 1] = min(cut[i + 1], cut[j] + 1);
		}
	}
	return cut[n];
}
