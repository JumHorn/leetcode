#include <vector>
using namespace std;

class Solution
{
public:
	bool kLengthApart(vector<int> &nums, int k)
	{
		int pre = -k - 1;
		for (int i = 0; i < (int)nums.size(); ++i)
		{
			if (nums[i] == 1)
			{
				if (i - pre - 1 < k)
					return false;
				pre = i;
			}
		}
		return true;
	}
};