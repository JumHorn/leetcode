#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
	vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
	{
		vector<int> v(nums.size() - k + 1);
		v[0] = accumulate(nums.begin(), nums.begin() + k, 0);
		for (int i = 1; i <= (int)nums.size() - k; i++)
			v[i] = v[i - 1] - nums[i - 1] + nums[i + k - 1];

		vector<int> res(3);
		vector<vector<int>> dp(4, vector<int>(v.size() + k));
		for (int i = 1; i < (int)dp.size(); i++)
		{
			for (int j = k; j < (int)dp[0].size(); j++)
				dp[i][j] = max(dp[i - 1][j - k] + v[j - k], dp[i][j - 1]);
		}

		for (int i = 2, j = dp[0].size() - 2; i >= 0; i--, j -= k)
		{
			while (dp[i + 1][j] == dp[i + 1][j + 1])
				--j;
			res[i] = j - k + 1;
		}
		return res;
	}
};