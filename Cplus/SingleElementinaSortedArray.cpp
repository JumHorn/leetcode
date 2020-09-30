#include <vector>
using namespace std;

class Solution
{
public:
	int singleNonDuplicate(vector<int> &nums)
	{
		int N = nums.size(), lo = 0, hi = N - 1;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (mi % 2 == 0)
			{
				if (mi != N - 1 && nums[mi] == nums[mi + 1])
					lo = mi + 2;
				else
					hi = mi;
			}
			else
			{
				if (mi != 0 && nums[mi] == nums[mi - 1])
					lo = mi + 1;
				else
					hi = mi;
			}
		}
		return nums[lo];
	}
};