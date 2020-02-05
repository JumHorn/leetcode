#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
	int threeSumClosest(vector<int> &nums, int target)
	{
		sort(nums.begin(), nums.end());
		int res = 0, diff = INT_MAX;
		for (int i = 0; i <= (int)nums.size() - 3; i++)
		{
			int tmp = target - nums[i], lo = i + 1, hi = nums.size() - 1;
			while (true)
			{
				while (lo < hi - 1 && nums[lo] + nums[hi] < tmp)
					++lo;
				int val;
				if (lo != i + 1)
				{
					val = abs(tmp - nums[lo - 1] - nums[hi]);
					if (val < diff)
					{
						diff = val;
						res = nums[i] + nums[lo-1] + nums[hi];
					}
				}
				val = abs(tmp - nums[lo] - nums[hi]);
				if (val < diff)
				{
					diff = val;
					res = nums[i] + nums[lo] + nums[hi];
				}
				while (lo < hi - 1 && nums[lo] + nums[hi] > tmp)
					--hi;
				if (nums[lo] + nums[hi] == tmp)
					return target;

				if (hi != nums.size() - 1)
				{
					val = abs(tmp - nums[lo] - nums[hi + 1]);
					if (val < diff)
					{
						diff = val;
						res = nums[i] + nums[lo] + nums[hi+1];
					}
				}
				val = abs(tmp - nums[lo] - nums[hi]);
				if (val < diff)
				{
					diff = val;
					res = nums[i] + nums[lo] + nums[hi];
				}
				if (lo >= hi - 1)
					break;
			}
		}
		return res;
	}
};