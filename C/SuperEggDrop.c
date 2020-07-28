#include <string.h>
/*
dp[m][k] m step and k eggs can reach highest
*/

int superEggDrop(int K, int N)
{
	int dp[K + 1];
	memset(dp, 0, sizeof(dp));
	int m = 0;
	while (dp[K] < N)
	{
		++m;
		for (int j = K; j > 0; --j)
			dp[j] = dp[j - 1] + dp[j] + 1;
	}
	return m;
}