#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int numLen(int x)
{
	if (x == 1)
		return 0;
	if (x < 10)
		return 1;
	if (x < 100)
		return 2;
	return 3;
}

int getLengthOfOptimalCompression(char *s, int k)
{
	int N = strlen(s);
	int dp[N + 1][k + 1];
	memset(dp, 1 << 6, sizeof(dp));
	memset(dp[0], 0, sizeof(dp[0]));
	for (int n = 0; n < N; ++n)
	{
		for (int j = 0; j <= k; ++j)
		{
			if (n < j) //remove all
			{
				dp[n + 1][j] = 0;
				continue;
			}
			int count[26] = {0}, most = 0; //count most freq number
			for (int i = n; i >= 0; --i)
			{
				++count[s[i] - 'a'];
				most = max(most, count[s[i] - 'a']);
				int removed = n - i + 1 - most;
				if (j < removed)
					break;
				dp[n + 1][j] = min(dp[n + 1][j], 1 + numLen(most) + dp[i][j - removed]);
			}
		}
	}
	return dp[N][k];
}