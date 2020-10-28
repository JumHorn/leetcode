#include <vector>
using namespace std;

class Solution
{
public:
	int findLengthOfLCIS(vector<int> &nums)
	{
		int res = 0, N = nums.size();
		for (int i = 1, j = 0; i <= N; ++i)
		{
			if (i == N || nums[i - 1] >= nums[i])
			{
				res = max(res, i - j);
				j = i;
			}
		}
		return res;
	}
};