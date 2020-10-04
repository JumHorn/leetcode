#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
	bool canPartitionKSubsets(vector<int> &nums, int k)
	{
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum % k != 0)
			return false;
		sum /= k;
		return backTracking(nums, 0, k, sum, sum);
	}

	bool backTracking(vector<int> &nums, int index, int k, int sub, int sum)
	{
		if (k == 1)
			return true;
		if (sub == 0)
			return backTracking(nums, 0, k - 1, sum, sum);
		for (int i = index; i < (int)nums.size(); ++i)
		{
			if (nums[i] < 0)
				continue;
			nums[i] = -nums[i];
			if (sub + nums[i] >= 0 && backTracking(nums, i + 1, k, sub + nums[i], sum))
				return true;
			nums[i] = -nums[i];
		}
		return false;
	}
};