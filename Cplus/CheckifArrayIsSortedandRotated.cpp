#include <vector>
using namespace std;

class Solution
{
public:
	bool check(vector<int> &nums)
	{
		int N = nums.size(), i = 1;
		while (i < N && nums[i] >= nums[i - 1])
			++i;
		if (i < N && nums.back() > nums[0])
			return false;
		for (++i; i < N; ++i)
		{
			if (nums[i] < nums[i - 1])
				return false;
		}
		return true;
	}
};