#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	void moveZeroes(vector<int> &nums)
	{
		for (int i = 0, j = 0; i < (int)nums.size(); ++i)
		{
			if (nums[i] != 0)
				swap(nums[i], nums[j++]);
		}
	}
};