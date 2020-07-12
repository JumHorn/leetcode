#include <vector>
using namespace std;

class Solution
{
public:
	int minDifference(vector<int>& nums)
	{
		int n = nums.size();
		if (n <= 4)
			return 0;
		sort(nums.begin(), nums.end());
		int res = INT_MAX;
		for (int i = 0, j = n - 4; i <= 3; i++, j++)
			res = min(res, nums[j] - nums[i]);
		return res;
	}
};
