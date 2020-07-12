#include <vector>
using namespace std;

class Solution
{
public:
	int numIdenticalPairs(vector<int>& nums)
	{
		int res = 0, n = nums.size();
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (nums[i] == nums[j])
					++res;
			}
		}
		return res;
	}
};
