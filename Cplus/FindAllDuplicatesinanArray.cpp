#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> findDuplicates(vector<int> &nums)
	{
		vector<int> res;
		for (int i = 0; i < (int)nums.size(); ++i)
		{
			int index = nums[i] - 1;
			if (nums[i] > 0)
			{
				if (nums[index] == 0)
				{
					res.push_back(nums[i]);
					nums[i] = nums[index] = -1;
				}
				else
				{
					nums[i] = nums[index];
					nums[index] = 0;
					--i; //still process from i
				}
			}
		}
		return res;
	}
};