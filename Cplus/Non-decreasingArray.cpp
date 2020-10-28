#include <vector>
using namespace std;

class Solution
{
public:
	bool checkPossibility(vector<int> &nums)
	{
		int op = 1; //modify operation
		for (int i = 1; i < (int)nums.size() && op >= 0; ++i)
		{
			if (nums[i - 1] > nums[i])
			{
				--op;
				if (i - 2 >= 0 && nums[i - 2] > nums[i])
					nums[i] = nums[i - 1];
			}
		}
		return op >= 0;
	}
};