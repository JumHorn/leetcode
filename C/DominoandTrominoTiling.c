#include <stdlib.h>

#define MOD ((int)(1e9 + 7))

int numTilings(int N)
{
	if (N < 3)
		return N;
	if (N == 3)
		return 5;
	int* dp = (int*)malloc(sizeof(int) * (N + 1));
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 5;
	for (int i = 4; i <= N; i++)
		dp[i] = (2 * dp[i - 1] % MOD + dp[i - 3]) % MOD;
	return dp[N];
}

