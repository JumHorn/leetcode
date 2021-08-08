#include <vector>
using namespace std;

class Solution
{
public:
	int minSpaceWastedKResizing(vector<int> &nums, int k)
	{
		int N = nums.size(), maxval = -1;
		vector<vector<int>> dp(N, vector<int>(k + 1));
		vector<int> prefixsum(N + 1);
		for (int i = 0; i < N; ++i)
			prefixsum[i + 1] = prefixsum[i] + nums[i];
		for (int i = 0; i < N; ++i)
		{
			maxval = max(maxval, nums[i]);
			dp[i][0] = waste(prefixsum, 0, i, maxval);
		}
		for (int j = 1; j <= k; ++j)
		{
			for (int i = 0; i < N; ++i)
			{
				dp[i][j] = dp[i][j - 1];
				maxval = -1;
				for (int l = i; l > 0; --l)
				{
					maxval = max(maxval, nums[l]);
					dp[i][j] = min(dp[i][j], dp[l - 1][j - 1] + waste(prefixsum, l, i, maxval));
				}
			}
		}
		return dp[N - 1][k];
	}

	int waste(vector<int> &prefix, int left, int right, int size)
	{
		long res = (long)(right - left + 1) * size;
		res -= prefix[right + 1] - prefix[left];
		return res;
	}
};