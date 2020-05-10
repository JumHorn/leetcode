#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int lengthOfLIS(vector<int> &nums)
	{
		if (nums.empty())
			return 0;
		vector<int> LIS;
		LIS.push_back(nums.front());
		for (int i = 1; i < (int)nums.size(); i++)
		{
			auto iter = lower_bound(LIS.begin(), LIS.end(), nums[i]);
			if (iter == LIS.end())
				LIS.push_back(nums[i]);
			else
				*iter = nums[i];
		}
		return LIS.size();
	}
};