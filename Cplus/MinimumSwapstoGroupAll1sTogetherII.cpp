#include <vector>
using namespace std;

class Solution
{
public:
	int minSwaps(vector<int> &nums)
	{
		return min(group(nums, 0), group(nums, 1));
	}

	int group(vector<int> &nums, int m)
	{
		int ones = 0, count = 0, N = nums.size();
		for (auto n : nums)
			ones += (n == m ? 1 : 0);
		for (int i = 0; i < ones; ++i)
			count += (nums[i] == m ? 1 : 0);
		int res = ones - count;
		for (int i = ones; i < N; ++i)
		{
			count += (nums[i] == m ? 1 : 0);
			count -= (nums[i - ones] == m ? 1 : 0);
			res = min(res, ones - count);
		}
		return res;
	}
};