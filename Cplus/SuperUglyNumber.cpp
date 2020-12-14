#include <climits>
#include <vector>
using namespace std;

/*
dp store ugly number in ascending order

primes[0] dp[0]×primes[0], dp[1]×primes[0], dp[2]×primes[0], dp[3]×primes[0], …
primes[1] dp[0]×primes[1], dp[1]×primes[1], dp[2]×primes[1], dp[3]×primes[1], …
primes[2] dp[0]×primes[2], dp[1]×primes[2], dp[2]×primes[2], dp[3]×primes[2], …
…, …, …
…, …, …
*/

class Solution
{
public:
	int nthSuperUglyNumber(int n, vector<int> &primes)
	{
		int N = primes.size();
		vector<int> dp(n, INT_MAX), lastIndex(N);
		dp[0] = 1;
		for (int i = 1; i < n; ++i)
		{
			for (int j = 0; j < N; ++j)
				dp[i] = min(dp[i], primes[j] * dp[lastIndex[j]]);
			for (int j = 0; j < N; ++j)
			{
				if (dp[i] == primes[j] * dp[lastIndex[j]])
					++lastIndex[j];
			}
		}
		return dp[n - 1];
	}
};