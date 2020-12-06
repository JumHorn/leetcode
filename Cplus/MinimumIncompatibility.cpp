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
		unordered_map<int, int> m; //{value,count}
		for (auto n : nums)
			++m[n];
		for (auto n : m)
		{
			if (n.second > k)
				return -1;
		}
		vector<int> compat(1 << N, -1); //{mask,diff}
		for (int i = 0; i < 1 << N; ++i)
		{
			if (bitCount(i) == bits && check(nums, i))
			{
				compat[i] = diff(nums, i);
			}
		}
		vector<vector<int>> dp(k + 1, vector<int>(1 << N, 1e9));
		dp[0][0] = 0;
		for (int a = 1; a <= k; ++a)
		{
			for (int i = (1 << N) - 1; i >= 0; --i)
			{
				if (dp[a - 1][i] >= 1e9)
					continue;
				int mask = ((~i) & ((1 << N) - 1));
				for (int j = mask; j > 0; j = ((j - 1) & mask))
				{
					if (compat[j] == -1)
						continue;
					int d = compat[j];
					if (dp[a - 1][i] + d < dp[a][i | j])
						dp[a][i | j] = dp[a - 1][i] + d;
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