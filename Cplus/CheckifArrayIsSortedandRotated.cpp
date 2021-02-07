#include <vector>
using namespace std;

class Solution
{
public:
	bool check(vector<int> &nums)
	{
		int peek = nums[0], N = nums.size(), i = 1;
		for (; i < N && nums[i] >= nums[i - 1]; ++i)
			;
		for (++i; i < N; ++i)
		{
			if (nums[i] < nums[i - 1])
				return false;
			if (nums[i] > peek)
				return false;
		}
		return true;
	}
};