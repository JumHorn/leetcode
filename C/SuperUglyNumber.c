#include <string.h>
/*
dp store ugly number in ascending order

primes[0] dp[0]×primes[0], dp[1]×primes[0], dp[2]×primes[0], dp[3]×primes[0], …
primes[1] dp[0]×primes[1], dp[1]×primes[1], dp[2]×primes[1], dp[3]×primes[1], …
primes[2] dp[0]×primes[2], dp[1]×primes[2], dp[2]×primes[2], dp[3]×primes[2], …
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