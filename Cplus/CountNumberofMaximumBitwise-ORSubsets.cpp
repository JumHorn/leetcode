#include <vector>
using namespace std;

class Solution
{
public:
	int countMaxOrSubsets(vector<int> &nums)
	{
		int N = nums.size(), res = 0, maxOR = 0;
		for (int mask = 0; mask < 1 << N; ++mask)
		{
			int val = 0;
			for (int i = 0; i < N; ++i)
			{
				if (mask & (1 << i))
				{
					val |= nums[i];
				}
			}
			if (val > maxOR)
			{
				maxOR = val;
				res = 1;
			}
			else if (val == maxOR)
				++res;
		}
		return res;
	}
};