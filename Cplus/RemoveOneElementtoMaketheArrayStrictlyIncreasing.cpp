#include <vector>
using namespace std;

class Solution
{
public:
	bool canBeIncreasing(vector<int> &nums)
	{
		int N = nums.size(), count = 0;
		for (int i = 1; i < N; ++i)
		{
			if (nums[i] <= nums[i - 1])
			{
				if (count != 0)
					return false;
				if (i != 1 && nums[i] <= nums[i - 2])
					nums[i] = nums[i - 1];
				count = 1;
			}
		}
		return true;
	}
};