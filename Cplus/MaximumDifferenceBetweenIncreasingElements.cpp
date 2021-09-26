#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maximumDifference(vector<int> &nums)
	{
		int res = -1, minval = nums[0], N = nums.size();
		for (int i = 1; i < N; ++i)
		{
			if (nums[i] > minval)
				res = max(res, nums[i] - minval);
			minval = min(minval, nums[i]);
		}
		return res;
	}
};