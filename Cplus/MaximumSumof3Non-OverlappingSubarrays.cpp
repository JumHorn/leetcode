#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
	{
		int N = nums.size();
		vector<int> ksum(N - k + 1);
		ksum[0] = accumulate(nums.begin(), nums.begin() + k, 0);
		for (int i = 1; i <= N - k; ++i) //slide window
			ksum[i] = ksum[i - 1] - nums[i - 1] + nums[i + k - 1];

		vector<vector<int>> dp(4, vector<int>(N + 1));
		for (int i = 1; i < (int)dp.size(); ++i)
		{
			for (int j = k; j <= N; ++j)
				dp[i][j] = max(dp[i - 1][j - k] + ksum[j - k], dp[i][j - 1]);
		}

		vector<int> res(3);
		for (int i = 2, j = N - 1; i >= 0; --i, j -= k)
		{
			while (dp[i + 1][j] == dp[i + 1][j + 1])
				--j;
			res[i] = j - k + 1;
		}
		return res;
	}
};