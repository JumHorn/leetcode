#include <algorithm>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
	{
		set<long> window;
		for (int i = 0; i < (int)nums.size(); i++)
		{
			if ((long)window.size() > k)
				window.erase(nums[i - k - 1]);
			set<long>::iterator iter = window.lower_bound((long)nums[i] - t);
			if (iter != window.end() && *iter - nums[i] <= t)
				return true;
			window.insert(nums[i]);
		}
		return false;
	}
};
