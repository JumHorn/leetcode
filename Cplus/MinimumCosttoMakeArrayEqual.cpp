#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	long long minCost(vector<int> &nums, vector<int> &cost)
	{
		int lo = *min_element(nums.begin(), nums.end()), hi = *max_element(nums.begin(), nums.end()) + 1;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (total(nums, cost, mi) > total(nums, cost, mi + 1))
				lo = mi + 1;
			else
				hi = mi;
		}
		return total(nums, cost, lo);
	}

	long long total(vector<int> &nums, vector<int> &cost, int avg)
	{
		long long res = 0, N = nums.size();
		for (int i = 0; i < N; ++i)
			res += (long long)abs(nums[i] - avg) * cost[i];
		return res;
	}
};