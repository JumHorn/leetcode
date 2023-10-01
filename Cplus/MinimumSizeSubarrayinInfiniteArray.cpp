#include <climits>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int minSizeSubarray(vector<int> &nums, int target)
	{
		long long sum = accumulate(nums.begin(), nums.end(), 0LL), N = nums.size();
		int res = INT_MAX, r = target / sum * N;
		target %= sum;
		for (int i = 0, j = 0; i < N * 2; ++i)
		{
			target -= nums[i % N];
			for (; target < 0; ++j)
				target += nums[j % N];
			if (target == 0)
				res = min(res, i - j + 1);
		}
		if (res == INT_MAX)
			return -1;
		return res + r;
	}
};