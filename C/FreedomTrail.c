#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int memdp(char *ring, int size, int index, char *key, int k, int (*dp)[size])
{
	if (!key[k])
		return 0;
	if (dp[k][index] != -1)
		return dp[k][index];
	int i = index, j = index, clockwise = 0, counterclockwise = 0, count = 0;
	while (key[k] != ring[i])
	{
		++i;
		if (i >= size)
			i = 0;
		++count;
	}
	clockwise = memdp(ring, size, i, key, k + 1, dp) + count + 1;
	count = 0;
	while (key[k] != ring[j])
	{
		if (j == 0)
			j = size;
		--j;
		++count;
	}
	counterclockwise = memdp(ring, size, j, key, k + 1, dp) + count + 1;
	return dp[k][index] = min(clockwise, counterclockwise);
}

int findRotateSteps(char *ring, char *key)
{
	int r = strlen(ring), k = strlen(key);
	int dp[k][r];
	memset(dp, -1, sizeof(dp));
	return memdp(ring, r, 0, key, 0, dp);
}