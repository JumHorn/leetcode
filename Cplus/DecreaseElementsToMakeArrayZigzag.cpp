#include <vector>
using namespace std;

class Solution
{
public:
	int movesToMakeZigzag(vector<int>& nums)
	{
		return min(countStep(nums, true), countStep(nums, false));
	}

	int countStep(vector<int>& nums, bool flag)
	{
		int n = nums.size(), res = 0, tmp = nums.front();
		for (int i = 1; i < n; i++)
		{
			if (flag)
			{
				if (nums[i] <= tmp)
					res += tmp - nums[i] + 1;
				tmp = nums[i];
			}
			else
			{
				if (nums[i] >= tmp)
				{
					res += nums[i] - tmp + 1;
					tmp = tmp - 1;
				}
				else
					tmp = nums[i];
			}
			flag = !flag;
		}
		return res;
	}
};
