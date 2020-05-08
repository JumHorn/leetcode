#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	int longestSubarray(vector<int>& nums, int limit)
	{
		int res = 1, maxval = nums[0], minval = nums[0];
		if (nums.empty())
			return 0;
		for (int i = 1; i < (int)nums.size(); i++)
		{
			if (nums[i] > maxval)
				maxval = nums[i];
			else if (nums[i] < minval)
				minval = nums[i];
			if (maxval - minval <= limit)
				res++;
			else
			{
				if (nums[i - res] == maxval)
					maxval = *max_element(nums.begin() + i - res + 1, nums.begin() + i + 1);
				if (nums[i - res] == minval)
					minval = *min_element(nums.begin() + i - res + 1, nums.begin() + i + 1);
			}
		}
		return res;
	}
};
