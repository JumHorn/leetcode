#include <stdbool.h>
#include <string.h>

bool canDecode(char* s, int index)
{
	int val = (s[index - 1] - '0') * 10 + (s[index] - '0');
	return val >= 10 && val <= 26;
}

int numDecodings(char* s)
{
	int N = strlen(s);
	if (N == 0)
		return 0;
	if (N == 1)
		return s[0] == '0' ? 0 : 1;
	int dp[N];
	memset(dp, 0, sizeof(dp));
	dp[0] = s[0] != '0' ? 1 : 0;
	dp[1] = (s[0] != '0' && s[1] != '0') ? 1 : 0;
	if (canDecode(s, 1))
		dp[1] += 1;
	for (int i = 2; i < N; ++i)
	{
		if (dp[i - 2] != 0 && canDecode(s, i))
			dp[i] += dp[i - 2];
		if (dp[i - 1] != 0 && s[i] != '0')
			dp[i] += dp[i - 1];
	}
	return dp[N - 1];
}
