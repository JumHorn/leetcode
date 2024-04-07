#include <vector>
using namespace std;

class Solution
{
public:
	int longestMonotonicSubarray(vector<int> &nums)
	{
		int N = nums.size(), res = 1;
		for (int i = 1, j = 0, k = 0; i <= N; ++i)
		{
			if (i == N || nums[i] <= nums[i - 1])
			{
				res = max(res, i - j);
				j = i;
			}
			if (i == N || nums[i] >= nums[i - 1])
			{
				res = max(res, i - k);
				k = i;
			}
		}
		return res;
	}
};