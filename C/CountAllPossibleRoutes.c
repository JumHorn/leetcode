#include <stdlib.h>
#include <string.h>

int countRoutes(int* locations, int locationsSize, int start, int finish, int fuel)
{
	static const int MOD = 1e9 + 7;
	int dp[locationsSize][fuel + 1];
	memset(dp, 0, sizeof(dp));
	for (int k = 1; k <= fuel; ++k)
	{
		for (int i = 0; i < locationsSize; ++i)
		{
			for (int j = 0; j < locationsSize; ++j)
			{
				int val = abs(locations[i] - locations[j]);
				if (i != j && val <= k)
					dp[i][k] = (dp[i][k] + dp[j][k - val] + (j == finish ? 1 : 0)) % MOD;
			}
		}
	}
	return dp[start][fuel] + (start == finish ? 1 : 0);
}
