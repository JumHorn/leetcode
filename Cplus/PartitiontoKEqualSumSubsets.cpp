#include <algorithm>
#include <numeric>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	bool canPartitionKSubsets(vector<int> &nums, int k)
	{
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum % k != 0)
			return false;
		sum /= k;
		int N = nums.size();
		unordered_set<int> subsets;
		for (int mask = 0; mask < 1 << N; ++mask)
		{
			int count = 0;
			for (int bit = 0; bit < N; ++bit)
			{
				if (mask & (1 << bit))
					count += nums[bit];
			}
			if (count == sum)
				subsets.insert(mask);
		}
		unordered_set<int> dp = subsets, next_dp;
		for (int i = 1; i < k; ++i)
		{
			for (auto n : subsets)
			{
				for (auto m : dp)
				{
					if (!(n & m))
						next_dp.insert(n | m);
				}
			}
			dp.swap(next_dp);
			next_dp.clear();
		}
		return dp.find((1 << N) - 1) != dp.end();
	}
};