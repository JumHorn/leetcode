#include <vector>
using namespace std;

class Solution
{
public:
	int findPeakElement(vector<int> &nums)
	{
		int lo = 0, hi = (int)nums.size() - 1;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (nums[mi] < nums[mi + 1])
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo;
	}
};