#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimizeMax(vector<int> &nums, int p)
	{
		sort(nums.begin(), nums.end());
		int lo = 0, hi = nums.back() - nums[0] + 1, N = nums.size();
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo, count = 0;
			for (int i = 1; i < N; ++i)
			{
				if (nums[i] - nums[i - 1] <= mi)
				{
					++i;
					++count;
				}
			}

			if (count < p)
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo;
	}
};