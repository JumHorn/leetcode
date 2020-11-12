#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int memdp(char *ring, int N, int index, char *key, int k, int (*dp)[N])
{
	if (!key[k])
		return 0;
	if (dp[k][index] != -1)
		return dp[k][index];
	int i = index, j = index, count = 0;
	for (count = 0; key[k] != ring[i]; ++count)
	{
		if (++i >= N)
			i = 0;
	}
	int clockwise = memdp(ring, N, i, key, k + 1, dp) + count + 1;
	for (count = 0; key[k] != ring[j]; ++count)
	{
		if (j-- == 0)
			j = N - 1;
	}
	int counterclockwise = memdp(ring, N, j, key, k + 1, dp) + count + 1;
	return dp[k][index] = min(clockwise, counterclockwise);
}

int findRotateSteps(char *ring, char *key)
{
	int r = strlen(ring), k = strlen(key);
	int dp[k][r];
	memset(dp, -1, sizeof(dp));
	return memdp(ring, r, 0, key, 0, dp);
}