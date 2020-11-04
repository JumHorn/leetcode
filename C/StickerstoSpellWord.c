#include <string.h>

int minStickers(char **stickers, int stickersSize, char *target)
{
	int N = strlen(target);
	int dp[1 << N];
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for (int state = 0; state < 1 << N; state++)
	{
		if (dp[state] == -1)
			continue;
		for (int i = 0; i < stickersSize; ++i)
		{
			int now = state;
			for (int j = 0; stickers[i][j]; ++j)
			{
				for (int k = 0; k < N; k++)
				{
					if (((now >> k) & 1) == 1)
						continue;
					if (target[k] == stickers[i][j])
					{
						now |= 1 << k;
						break;
					}
				}
			}
			if (dp[now] == -1 || dp[now] > dp[state] + 1)
				dp[now] = dp[state] + 1;
		}
	}
	return dp[(1 << N) - 1];
}
