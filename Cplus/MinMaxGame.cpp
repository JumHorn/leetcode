#include <vector>
using namespace std;

class Solution
{
public:
	int minMaxGame(vector<int> &nums)
	{
		while (nums.size() > 1)
		{
			vector<int> next;
			bool flag = true;
			for (int i = 0; i < (int)nums.size(); i += 2)
			{
				if (flag)
					next.push_back(min(nums[i], nums[i + 1]));
				else
					next.push_back(max(nums[i], nums[i + 1]));
				flag = !flag;
			}
			nums = next;
		}
		return nums[0];
	}
};