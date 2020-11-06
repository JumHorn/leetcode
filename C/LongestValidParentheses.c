#include <string.h>

/*
dp[i] means ith index has matched length dp[i]
s[i] == '(' dp[i] = 0
s[i] == ')'
	1. s[i-1] == '(' dp[i]=2+dp[i-2]
	2. s[i-1] == ')'
		s[i-1-dp[i-1]] == '(' ? dp[i]=2+dp[i-1]+dp[i-1-dp[i-1]-1]

initialization
dp[0]=0
*/

#define max(a, b) (((a) > (b)) ? (a) : (b))

int longestValidParentheses(char *s)
{
	int N = strlen(s), dp[N + 1], res = 0;
	dp[0] = 0;
	for (int i = 1; i < N; ++i)
	{
		if (s[i] == ')')
		{
			if (s[i - 1] == '(')
				dp[i] = 2 + (i >= 2 ? dp[i - 2] : 0);
			else if (i > dp[i - 1] && s[i - 1 - dp[i - 1]] == '(')
				dp[i] = 2 + dp[i - 1] + (i - 2 >= dp[i - 1] ? dp[i - 2 - dp[i - 1]] : 0);
			else
				dp[i] = 0;
		}
		else
			dp[i] = 0;
		res = max(res, dp[i]);
	}
	return res;
}