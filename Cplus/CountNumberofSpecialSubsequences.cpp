#include <vector>
using namespace std;

class Solution
{
public:
	int countSpecialSubsequences(vector<int> &nums)
	{
		vector<int> dp = {1, 0, 0, 0};
		for (auto n : nums)
			dp[n + 1] = (dp[n + 1] * 2 + dp[n]) % MOD;
		return dp.back();
	}

private:
	static const int MOD = 1e9 + 7;
};