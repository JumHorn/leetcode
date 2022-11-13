#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumIncompatibility(vector<int> &nums, int k)
	{
		int N = nums.size(), bits = N / k, INF = 1e9;
		sort(nums.begin(), nums.end());
		for (int i = 0, j = 0; i <= N; ++i)
		{
			if (i == N || nums[i] != nums[j])
			{
				if (i - j > k)
					return -1;
				j = i;
			}
		}
		vector<int> combo(1 << N, -1); //{mask,diff}
		for (int mask = 0; mask < 1 << N; ++mask)
		{
			if (bitCount(mask) == bits && check(nums, mask))
				combo[mask] = diff(nums, mask);
		}
		vector<vector<int>> dp(k + 1, vector<int>(1 << N, INF));
		dp[0][0] = 0;
		for (int i = 0; i < k; ++i)
		{
			for (int mask = (1 << N) - 1; mask >= 0; --mask)
			{
				if (dp[i][mask] >= INF)
					continue;
				int m = ((~mask) & ((1 << N) - 1));
				for (int j = m; j > 0; j = ((j - 1) & m))
				{
					if (combo[j] != -1 && dp[i][mask] + combo[j] < dp[i + 1][mask | j])
						dp[i + 1][mask | j] = dp[i][mask] + combo[j];
				}
			}
		}
		return dp[k][(1 << N) - 1];
	}

	bool check(vector<int> &nums, int mask)
	{
		int pre = -1;
		for (int i = 0; i < 16; ++i)
		{
			if (mask & (1 << i))
			{
				if (pre == nums[i])
					return false;
				pre = nums[i];
			}
		}
		return true;
	}

	int diff(vector<int> &nums, int mask)
	{
		int minval = INT_MAX, maxval = INT_MIN;
		for (int i = 0; i < 16; ++i)
		{
			if (mask & (1 << i))
			{
				maxval = max(maxval, nums[i]);
				minval = min(minval, nums[i]);
			}
		}
		return maxval - minval;
	}

	int bitCount(int n)
	{
		int res = 0;
		for (; n != 0; n &= n - 1)
			++res;
		return res;
	}
};