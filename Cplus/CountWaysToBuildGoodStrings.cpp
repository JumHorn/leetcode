#include <vector>
using namespace std;

class Solution
{
public:
	int countGoodStrings(int low, int high, int zero, int one)
	{
		vector<long long> dp(high + 1);
		dp[0] = 1;
		long long res = 0;
		for (int i = 1; i <= high; ++i)
		{
			if (i >= zero)
				dp[i] = (dp[i] + dp[i - zero]) % MOD;
			if (i >= one)
				dp[i] = (dp[i] + dp[i - one]) % MOD;
			if (i >= low)
				res = (res + dp[i]) % MOD;
		}
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};