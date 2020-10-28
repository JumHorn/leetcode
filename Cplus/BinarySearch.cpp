#include <vector>
using namespace std;

class Solution
{
public:
	int search(vector<int> &nums, int target)
	{
		if (nums.empty())
			return -1;
		int lo = 0, hi = (int)nums.size() - 1;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (nums[mi] < target)
				lo = mi + 1;
			else
				hi = mi;
		}
		return nums[lo] == target ? lo : -1;
	}
};