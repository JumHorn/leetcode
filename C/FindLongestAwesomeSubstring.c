#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int longestAwesome(char *s)
{
	int dp[1024], N = strlen(s);
	dp[0] = -1;
	memset(dp, 1 << 6, sizeof(dp));
	int res = 0, mask = 0;
	for (int i = 0; i < N; ++i)
	{
		int bit = s[i] - '0';
		mask ^= 1 << bit;
		res = max(res, i - dp[mask]);
		for (int j = 0; j < 10; ++j)
			res = max(res, i - dp[mask ^ (1 << j)]);
		dp[mask] = min(dp[mask], i);
	}
	return res;
}