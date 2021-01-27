#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

char *stoneGameIII(int *stoneValue, int stoneValueSize)
{
	int N = stoneValueSize;
	int dp[N + 1], prefixsum[N + 1];
	prefixsum[0] = 0;
	for (int i = 0; i < N; ++i)
		prefixsum[i + 1] = prefixsum[i] + stoneValue[i];
	int all = prefixsum[N];
	memset(dp, 1u << 7, sizeof(dp)); //init to 0x80808080 a large minus number
	dp[N] = 0;
	for (int i = N - 1; i >= 0; --i)
	{
		for (int j = i; j < min(N, i + 3); ++j)
		{
			int other = all - prefixsum[i] - dp[j + 1];
			dp[i] = max(dp[i], other);
		}
	}
	if (2 * dp[0] > all)
		return "Alice";
	if (2 * dp[0] < all)
		return "Bob";
	return "Tie";
}