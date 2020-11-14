#include <string.h>

int minStickers(char **stickers, int stickersSize, char *target)
{
	int N = strlen(target);
	int dp[1 << N];
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for (int mask = 0; mask < 1 << N; ++mask)
	{
		if (dp[mask] == -1)
			continue;
		for (int i = 0; i < stickersSize; ++i)
		{
			int next_mask = mask;
			for (int j = 0; stickers[i][j]; ++j)
			{
				for (int k = 0; k < N; ++k)
				{
					if (((next_mask >> k) & 1) == 1)
						continue;
					if (target[k] == stickers[i][j])
					{
						next_mask |= 1u << k;
						break;
					}
				}
			}
			if (dp[next_mask] == -1 || dp[next_mask] > dp[mask] + 1)
				dp[next_mask] = dp[mask] + 1;
		}
	}
	return dp[(1 << N) - 1];
}