#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int countPartitions(vector<int> &nums, int k)
	{
		long long sum = accumulate(nums.begin(), nums.end(), 0LL);
		if (sum < k * 2)
			return 0;
		vector<int> dp(k);
		dp[0] = 1;
		int res = 1;
		for (auto n : nums)
		{
			res = res * 2 % MOD;
			for (int i = k - 1; i >= n; --i)
				dp[i] = (dp[i] + dp[i - n]) % MOD;
		}
		for (auto n : dp)
			res = (res - n * 2 % MOD + MOD) % MOD;
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};