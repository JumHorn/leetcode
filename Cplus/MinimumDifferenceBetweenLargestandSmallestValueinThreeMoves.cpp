#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
	int minDifference(vector<int> &nums)
	{
		int N = nums.size();
		if (N <= 4)
			return 0;
		sort(nums.begin(), nums.end());
		int res = INT_MAX;
		for (int i = 0, j = N - 4; i <= 3; ++i, ++j)
			res = min(res, nums[j] - nums[i]);
		return res;
	}
};