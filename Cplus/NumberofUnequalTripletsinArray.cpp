#include <vector>
using namespace std;

class Solution
{
public:
	int unequalTriplets(vector<int> &nums)
	{
		int res = 0, N = nums.size();
		for (int i = 0; i < N; ++i)
		{
			for (int j = i + 1; j < N; ++j)
			{
				for (int k = j + 1; k < N; ++k)
				{
					if (nums[i] != nums[j] && nums[j] != nums[k] && nums[i] != nums[k])
						++res;
				}
			}
		}
		return res;
	}
};