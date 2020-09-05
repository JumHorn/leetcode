#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int bitCount(int n)
{
	int res = 0;
	while (n != 0)
	{
		++res;
		n &= n - 1;
	}
	return res;
}

int minNumberOfSemesters(int n, int **dependencies, int dependenciesSize, int *dependenciesColSize, int k)
{
	int prerequisite[n];
	memset(prerequisite, 0, sizeof(prerequisite));
	for (int i = 0; i < dependenciesSize; ++i)
		prerequisite[dependencies[i][1] - 1] |= 1 << (dependencies[i][0] - 1);
	int dp[1 << n];
	memset(dp, 1 << 6, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i < 1 << n; ++i)
	{
		int readyfortake = 0;
		for (int j = 0; j < n; ++j)
		{
			if ((prerequisite[j] & i) == prerequisite[j])
				readyfortake |= 1 << j;
		}
		readyfortake &= ~i;
		for (int j = readyfortake; j > 0; j = (j - 1) & readyfortake)
		{
			if (bitCount(j) <= k)
				dp[i | j] = min(dp[i | j], dp[i] + 1);
		}
	}
	return dp[(1 << n) - 1];
}