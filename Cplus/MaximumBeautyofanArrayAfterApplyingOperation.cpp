#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maximumBeauty(vector<int> &nums, int k)
	{
		sort(nums.begin(), nums.end());
		int res = 1, N = nums.size();
		for (int i = 0, j = 0; i <= N; ++i)
		{
			if (i == N || nums[i] - nums[j] > 2 * k)
			{
				res = max(res, i - j);
				if (i < N)
				{
					while (nums[i] - nums[j] > 2 * k)
						++j;
				}
			}
		}
		return res;
	}
};