#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int smallestDistancePair(vector<int> &nums, int k)
	{
		sort(nums.begin(), nums.end());
		int hi = nums.back() - nums.front(), lo = 0, N = nums.size();
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;

			int count = 0;
			for (int i = 0, j = 0; i < N; ++i)
			{
				while (nums[i] - nums[j] > mi)
					++j;
				count += i - j;
			}

			if (count < k)
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo;
	}
};