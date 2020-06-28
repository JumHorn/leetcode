#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int numSubseq(vector<int> &nums, int target)
	{
		sort(nums.begin(), nums.end());
		long res = 0;
		int i = 0, n = nums.size();
		while (i < n && nums[i] * 2 <= target)
			++i;
		res = powCache(i) - 1;
		for (; i < n; ++i)
		{
			auto iter = upper_bound(nums.begin(), nums.begin() + i, target - nums[i]);
			int count = iter - nums.begin();
			res = (res + (powCache(count) - 1) * powCache(i - count)) % MOD;
		}
		return res;
	}

	long powCache(int n)
	{
		if (cache.empty())
			cache.push_back(1);
		if (n < (int)cache.size())
			return cache[n];
		while (n >= (int)cache.size())
			cache.push_back(cache.back() * 2 % MOD);
		return cache.back();
	}

private:
	vector<int> cache;
	static const int MOD = 1e9 + 7;
};