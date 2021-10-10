#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumDifference(vector<int> &nums)
	{
		int sum = accumulate(nums.begin(), nums.end(), 0), res = INT_MAX, N = nums.size(), n = N / 2;
		vector<int> v1(1 << n);
		calc(nums, v1);

		vector<vector<int>> v2(n + 1);
		for (int mask = 0; mask < 1 << n; ++mask)
		{
			int index = bitCount(mask);
			int count = 0;
			for (int i = 0; i < n; ++i)
			{
				if (mask & (1 << i))
					count += nums[i + n];
			}
			v2[index].push_back(count * 2);
		}
		for (auto &v : v2)
			sort(v.begin(), v.end());

		for (int mask1 = 0; mask1 < 1 << n; ++mask1)
		{
			int index = n - bitCount(mask1);
			int count = (sum - 2 * v1[mask1]);
			auto iter = lower_bound(v2[index].begin(), v2[index].end(), count);
			if (iter != v2[index].end())
				res = min(res, abs(count - *iter));
			if (iter != v2[index].begin())
			{
				--iter;
				res = min(res, abs(count - *iter));
			}
		}
		return res;
	}

	void calc(vector<int> &nums, vector<int> &v)
	{
		int n = nums.size() / 2;
		for (int mask = 0; mask < 1 << n; ++mask)
		{
			int count = 0;
			for (int i = 0; i < n; ++i)
			{
				if (mask & (1 << i))
					count += nums[i];
			}
			v[mask] = count;
		}
	}

	int bitCount(int n)
	{
		int res = 0;
		for (; n != 0; n &= n - 1)
			++res;
		return res;
	}
};