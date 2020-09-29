#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int longestPalindromeSubseq(char *s)
{
	int N = strlen(s);
	int dp[N];
	memset(dp, 0, sizeof(dp));
	for (int i = N - 1; i >= 0; --i)
	{
		dp[i] = 1;
		int pre = 0, next;
		for (int j = i + 1; j < N; ++j)
		{
			next = dp[j];
			if (s[i] == s[j])
				dp[j] = pre + 2;
			else
				dp[j] = max(dp[j], dp[j - 1]);
			pre = next;
		}
	}
	return dp[N - 1];
}