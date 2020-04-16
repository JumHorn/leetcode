#include <vector>
using namespace std;

class Solution
{
public:
	int findMin(vector<int> &nums)
	{
		int lo = 0, hi = nums.size() - 1;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (nums[mi] > nums[hi])
			{
				lo = mi + 1;
			}
			else if (nums[mi] < nums[hi])
			{
				hi = mi;
			}
			else // when num[mid] and num[hi] are same
			{
				hi--;
			}
		}
		return nums[lo];
	}
};