#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumDifference(vector<int> &nums, int k)
	{
		sort(nums.begin(), nums.end());
		int res = INT_MAX, N = nums.size();
		for (int i = k - 1; i < N; ++i)
			res = min(res, nums[i] - nums[i - k + 1]);
		return res;
	}
};