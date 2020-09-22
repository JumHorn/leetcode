#include <string.h>
/*
primes[0] 1×primes[0], 2×primes[0], 3×primes[0], 4×primes[0], 5×primes[0], …
primes[1] 1×primes[1], 2×primes[1], 3×primes[1], 4×primes[1], 5×primes[1], …
primes[2] 1×primes[2], 2×primes[2], 3×primes[2], 4×primes[2], 5×primes[2], …
…, …, …
…, …, …
*/

#define min(a, b) (((a) < (b)) ? (a) : (b))

int nthSuperUglyNumber(int n, int *primes, int primesSize)
{
	int dp[n], lastIndex[primesSize];
	memset(dp, (1u << 7) - 1, sizeof(dp));
	memset(lastIndex, 0, sizeof(lastIndex));
	dp[0] = 1;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < primesSize; ++j)
			dp[i] = min(dp[i], primes[j] * dp[lastIndex[j]]);
		for (int j = 0; j < primesSize; ++j)
		{
			if (dp[i] == primes[j] * dp[lastIndex[j]])
				++lastIndex[j];
		}
	}
	return dp[n - 1];
}