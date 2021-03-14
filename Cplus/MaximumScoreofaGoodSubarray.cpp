#include <vector>
using namespace std;

class Solution
{
public:
	int maximumScore(vector<int> &nums, int k)
	{
		int res = nums[k], N = nums.size(), cur = nums[k];
		for (int i = k, j = k; i < N; ++i)
		{
			cur = min(cur, nums[i]);
			while (j >= 0 && nums[j] >= cur)
				--j;
			res = max(res, cur * (i - j));
		}
		cur = nums[k];
		for (int i = k, j = k; i >= 0; --i)
		{
			cur = min(cur, nums[i]);
			while (j < N && nums[j] >= cur)
				++j;
			res = max(res, cur * (j - i));
		}
		return res;
	}
};