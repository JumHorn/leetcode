#include <string.h>

int memdp(int N, int index, int mask, int (*dp)[N])
{
	if (index >= N)
		return 1;
	if (dp[mask][index] != -1)
		return dp[mask][index];
	int res = 0;
	for (int i = 0; i < N; ++i)
	{
		if ((mask & (1 << i)) == 0)
		{
			if ((i + 1) % (index + 1) == 0 || (index + 1) % (i + 1) == 0)
				res += memdp(N, index + 1, mask | (1 << i), dp);
		}
	}
	return dp[mask][index] = res;
}

int countArrangement(int N)
{
	int dp[1 << N][N];
	memset(dp, -1, sizeof(dp));
	return memdp(N, 0, 0, dp);
}