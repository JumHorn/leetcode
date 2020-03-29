#include <string.h>

/*
using stack to track every )'s index

dp[i] ith index has length dp[i]
if i+1 ) has matched ( dp[i+1]=dp[i]+2+dp[stack.top()]
dp[i+1]=0

initialization
dp[0]=0
*/

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define LEN 20001

int longestValidParentheses(char *s)
{
	int dp[LEN] = {0}, size = 0, res = 0, top = -1, stack[LEN] = {0};
	char *p = s;
	while (*p)
	{
		if (*p == '(')
		{
			stack[++top] = size;
			dp[++size] = 0;
		}
		else
		{
			if (top != -1)
			{
				dp[size + 1] = dp[stack[top--]] + dp[size] + 2;
				res = max(res, dp[size + 1]);
			}
			else
				dp[size + 1] = 0;
			++size;
		}
		++p;
	}
	return res;
}
