#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxSumRangeQuery(vector<int> &nums, vector<vector<int>> &requests)
	{
		int N = nums.size();
		vector<int> dp(N + 1);
		for (auto &r : requests)
		{
			++dp[r[0]];
			--dp[r[1] + 1];
		}
		sort(nums.begin(), nums.end(), greater<int>());
		for (int i = 1; i < N; ++i)
			dp[i] += dp[i - 1];
		sort(dp.begin(), dp.end(), greater<int>());
		long res = 0;
		for (int i = N - 1; i >= 0; --i)
			res = (res + dp[i] * nums[i]) % MOD;
		return res;
	}

private:
	static const int MOD = 1e9 + 7;
};