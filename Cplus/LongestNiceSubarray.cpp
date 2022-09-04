#include <vector>
using namespace std;

class Solution
{
public:
	int longestNiceSubarray(vector<int> &nums)
	{
		int res = 0, mask = 0, N = nums.size();
		for (int i = 0, j = 0; i < N; ++i)
		{
			for (; (nums[i] & mask) != 0; ++j)
				mask ^= nums[j];
			mask ^= nums[i];
			res = max(res, i - j + 1);
		}
		return res;
	}
};