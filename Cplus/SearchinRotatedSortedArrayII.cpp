#include <vector>
using namespace std;

class Solution
{
public:
	bool search(vector<int> &nums, int target)
	{
		if (nums.empty())
			return false;
		int N = nums.size(), lo = 0, hi = N - 1;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (nums[mi] == nums[hi]) //worst case O(N)
			{
				if (nums[hi - 1] > nums[hi])
				{
					lo = hi;
					break;
				}
				--hi;
			}
			else if (nums[mi] > nums[hi])
				lo = mi + 1;
			else
				hi = mi;
		}
		if (target <= nums[N - 1])
			return binarySearch(nums, lo, N - 1, target);
		return binarySearch(nums, 0, lo - 1, target);
	}

	bool binarySearch(vector<int> &nums, int lo, int hi, int target)
	{
		while (lo <= hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (target == nums[mi])
				return true;
			if (target > nums[mi])
				lo = mi + 1;
			else
				hi = mi - 1;
		}
		return false;
	}
};