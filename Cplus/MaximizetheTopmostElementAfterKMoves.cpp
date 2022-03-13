#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maximumTop(vector<int> &nums, int k)
	{
		int top = -1, N = nums.size();
		if (k == 0)
			return nums[0];
		if (N == 1)
		{
			if (k % 2 == 0)
				return nums[0];
			return -1;
		}
		if (k == 1)
			return nums[1];
		if (k > N)
			return *max_element(nums.begin(), nums.end());
		int res = *max_element(nums.begin(), nums.begin() + k - 1);
		if (k < N)
			res = max(res, nums[k]);
		return res;
	}
};