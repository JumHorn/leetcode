#include <vector>
using namespace std;

class Solution
{
public:
	int search(vector<int> &nums, int target)
	{
		int N = nums.size(), lo = 0, hi = N - 1;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (nums[mi] > nums[hi])
				lo = mi + 1;
			else
				hi = mi;
		}
		if (target <= nums[N - 1])
			return binarySearch(nums, lo, N - 1, target);
		return binarySearch(nums, 0, lo - 1, target);
	}

	int binarySearch(vector<int> &nums, int lo, int hi, int target)
	{
		while (lo <= hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (target == nums[mi])
				return mi;
			if (target > nums[mi])
				lo = mi + 1;
			else
				hi = mi - 1;
		}
		return -1;
	}
};