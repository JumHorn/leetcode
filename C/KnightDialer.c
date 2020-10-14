#include <string.h>

int knightDialer(int n)
{
	static const int MOD = 1e9 + 7;
	int graph[10][3] = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {0, 3, 9}, {}, {0, 1, 7}, {2, 6}, {1, 3}, {2, 4}};
	int graphColSize[10] = {2, 2, 2, 2, 3, 0, 3, 2, 2, 2};
	int dp[10];
	for (int i = 0; i < 10; ++i)
		dp[i] = 1;
	for (int i = 1; i < n; ++i)
	{
		int nextdp[10] = {0};
		for (int j = 0; j < 10; ++j)
		{
			for (int k = 0; k < graphColSize[j]; ++k)
				nextdp[graph[j][k]] = (nextdp[graph[j][k]] + dp[j]) % MOD;
		}
		memcpy(dp, nextdp, sizeof(dp));
	}
	int res = 0;
	for (int i = 0; i < 10; ++i)
		res = (res + dp[i]) % MOD;
	return res;
}
