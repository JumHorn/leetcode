#include <climits>
#include <set>
#include <vector>
using namespace std;

class Solution
{
public:
	int minAbsoluteDifference(vector<int> &nums, int x)
	{
		set<int> s;
		int N = nums.size(), res = INT_MAX;
		for (int i = 0, j = x; j < N; ++i, ++j)
		{
			s.insert(nums[i]);
			auto it = s.lower_bound(nums[j]);
			if (it != s.end())
				res = min(res, *it - nums[j]);
			if (it != s.begin())
				res = min(res, nums[j] - *(--it));
		}
		return res;
	}
};