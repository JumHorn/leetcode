#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int triangleNumber(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());
		int res = 0, N = nums.size();
		for (int i = 0; i < N - 2; ++i)
		{
			for (int j = i + 1; j < N - 1; ++j)
			{
				auto iter = lower_bound(nums.begin() + j + 1, nums.end(), nums[i] + nums[j]);
				res += iter - nums.begin() - j - 1;
			}
		}
		return res;
	}
};