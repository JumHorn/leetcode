#include <algorithm>
#include <vector>
using namespace std;

/*
O(N) only need to check the range between max right jump and next max right jump
*/

class Solution
{
public:
	int jump(vector<int> &nums)
	{
		int res = 0, curEnd = 0, curFarthest = 0, N = nums.size();
		if (N < 2)
			return 0;
		for (int i = 0; i + nums[i] < N - 1; ++i)
		{
			curFarthest = max(curFarthest, i + nums[i]);
			if (i == curEnd)
			{
				++res;
				curEnd = curFarthest;
			}
		}
		return res + 1;
	}
};