#include <string.h>

int numDecodings(char *s)
{
	static const int MOD = 1e9 + 7;
	int len = strlen(s);
	if (len == 0)
		return 0;
	if (len == 1)
		return *s == '*' ? 9 : (*s == '0' ? 0 : 1);
	long dp[len + 1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	dp[1] = *s == '*' ? 9 : (*s == '0' ? 0 : 1);
	for (int i = 1; i < len; ++i)
	{
		dp[i + 1] = (dp[i + 1] + dp[i] * (s[i] == '*' ? 9 : (s[i] == '0' ? 0 : 1))) % MOD;
		int k = 0;
		if (s[i - 1] == '*' && s[i] == '*')
			k = 15;
		else if (s[i - 1] == '*' && s[i] != '*')
		{
			k = 2;
			if (s[i] - '0' > 6)
				--k;
		}
		else if (s[i - 1] != '*' && s[i] == '*')
		{
			if (s[i - 1] != '0')
			{
				for (int j = 1; j < 10 && (s[i - 1] - '0') * 10 + j <= 26; j++)
					k++;
			}
		}
		else
		{
			int tmp = (s[i - 1] - '0') * 10 + s[i] - '0';
			if (tmp >= 10 && tmp <= 26)
				k = 1;
		}
		dp[i + 1] = (dp[i + 1] + k * dp[i - 1]) % MOD;
	}
	return dp[len];
}