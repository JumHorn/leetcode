#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumIncompatibility(vector<int> &nums, int k)
	{
		int N = nums.size();
		int bits = N / k;
		int res = 0;
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
		for (int i = 0; i < 1 << N; ++i)
		{
			if (bitCount(i) == bits && check(nums, i))
				combo[i] = diff(nums, i);
		}
		vector<vector<int>> dp(k + 1, vector<int>(1 << N, 1e9));
		dp[0][0] = 0;
		for (int n = 0; n < k; ++n)
		{
			for (int i = (1 << N) - 1; i >= 0; --i)
			{
				if (dp[n][i] >= 1e9)
					continue;
				int mask = ((~i) & ((1 << N) - 1));
				for (int j = mask; j > 0; j = ((j - 1) & mask))
				{
					if (combo[j] == -1)
						continue;
					int d = combo[j];
					if (dp[n][i] + d < dp[n + 1][i | j])
						dp[n + 1][i | j] = dp[n][i] + d;
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