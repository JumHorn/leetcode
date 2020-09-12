#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> searchRange(vector<int> &nums, int target)
	{
		if (nums.empty() || target < nums.front() || target > nums.back())
			return {-1, -1};
		int lower = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
		if (nums[lower] != target)
			return {-1, -1};
		int upper = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
		return {lower, upper - 1};
	}
};