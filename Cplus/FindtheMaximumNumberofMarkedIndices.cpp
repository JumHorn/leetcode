#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maxNumOfMarkedIndices(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());
		int res = 0, val = nums.back() / 2, N = nums.size();
		auto it = upper_bound(nums.begin(), nums.end(), val);
		if (it == nums.begin())
			return 0;
		--it;
		int i = it - nums.begin(), j = N - 1;
		for (; j >= 0 && i >= 0; --j)
		{
			if (nums[j] < 0)
				continue;
			while (i >= 0 && nums[i] > nums[j] / 2)
				--i;
			if (i >= 0)
			{
				nums[i] = nums[j] = -1;
				res += 2;
				--i;
			}
		}
		return res;
	}
};