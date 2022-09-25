#include <vector>
using namespace std;

class Solution
{
public:
	int longestSubarray(vector<int> &nums)
	{
		int res = 0, val = 0, N = nums.size();
		for (int i = 0, j = 0; j <= N; ++j)
		{
			if (j == N || nums[i] != nums[j])
			{
				if (val < nums[i])
				{
					res = j - i;
					val = nums[i];
				}
				else if (val == nums[i])
					res = max(res, j - i);
				i = j;
			}
		}
		return res;
	}
};