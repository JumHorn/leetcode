#include <string.h>

int memdp(int (*map)[10], int hat, int mask, int allmask, int (*dp)[1 << 10])
{
	static const int MOD = 1e9 + 7;
	if (mask == allmask)
		return 1;
	if (hat >= 41)
		return 0;
	if (dp[hat][mask] != -1)
		return dp[hat][mask];
	int res = memdp(map, hat + 1, mask, allmask, dp);
	for (int i = 0; i < 10; i++)
	{
		if (map[hat][i] == 0 || (mask & (1 << i)))
			continue;
		res = (res + memdp(map, hat + 1, mask | (1 << i), allmask, dp)) % MOD;
	}
	dp[hat][mask] = res;
	return res;
}

int numberWays(int** hats, int hatsSize, int* hatsColSize)
{
	int map[41][10] /*hats to people*/, dp[41][1 << 10];
	memset(map, 0, sizeof(map));
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < hatsSize; i++)
	{
		for (int j = 0; j < hatsColSize[i]; j++)
			map[hats[i][j]][i] = 1;
	}
	return memdp(map, 1, 0, (1 << hatsSize) - 1, dp);
}
