#include <climits>
#include <vector>
using namespace std;

/*
primes[0] 1×primes[0], 2×primes[0], 3×primes[0], 4×primes[0], 5×primes[0], …
primes[1] 1×primes[1], 2×primes[1], 3×primes[1], 4×primes[1], 5×primes[1], …
primes[2] 1×primes[2], 2×primes[2], 3×primes[2], 4×primes[2], 5×primes[2], …
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