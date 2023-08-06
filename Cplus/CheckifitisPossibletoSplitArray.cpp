#include <vector>
using namespace std;

class Solution
{
public:
	bool canSplitArray(vector<int> &nums, int m)
	{
		int N = nums.size();
		if (N <= 2)
			return true;
		for (int i = 0; i < N - 1; ++i)
		{
			if (nums[i] + nums[i + 1] >= m)
				return true;
		}
		return false;
	}
};