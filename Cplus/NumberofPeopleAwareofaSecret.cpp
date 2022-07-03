#include <vector>
using namespace std;

class Solution
{
public:
	int peopleAwareOfSecret(int n, int delay, int forget)
	{
		vector<long> dp(n + 1);
		dp[1] = 1;
		long sum = 0;
		for (int i = 2; i <= n; ++i)
		{
			if (i - delay >= 1)
				sum = (sum + dp[i - delay]) % MOD;
			if (i - forget >= 1)
				sum = (sum - dp[i - forget] + MOD) % MOD;
			dp[i] = sum;
		}

		long res = 0;
		for (int i = n; i >= 0 && i > n - forget; --i)
			res = (res + dp[i]) % MOD;
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};