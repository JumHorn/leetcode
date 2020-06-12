#include <string.h>

int strangePrinter(char* s)
{
	if (!*s)
		return 0;
	int len = strlen(s);
	int dp[len + 1][len + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 0; i < len; i++)
		dp[i][i] = 1;
	for (int n = 1; n < len; n++)
	{
		for (int i = 0; i < len - n; i++)
		{
			int j = i + n;
			dp[i][j] = dp[i + 1][j] + 1;
			for (int k = i + 1; k <= j; k++)
			{
				if (s[i] == s[k] && dp[i][j] > dp[i][k - 1] + dp[k + 1][j])
					dp[i][j] = dp[i][k - 1] + dp[k + 1][j];
			}
		}
	}
	return dp[0][len - 1];
}
