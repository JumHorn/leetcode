#include <vector>
using namespace std;

class Solution
{
public:
	int countHousePlacements(int n)
	{
		vector<long long> dp(4), next_dp(4);
		dp[0] = 1;
		for (int i = 0; i < n; ++i)
		{
			next_dp[0] = (dp[0] + dp[1] + dp[2] + dp[3]) % MOD;
			next_dp[1] = (dp[0] + dp[2]) % MOD;
			next_dp[2] = (dp[0] + dp[1]) % MOD;
			next_dp[3] = dp[0];

			copy(next_dp.begin(), next_dp.end(), dp.begin());
			fill(next_dp.begin(), next_dp.end(), 0);
		}

		long long res = 0;
		for (auto n : dp)
			res = (res + n) % MOD;
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};