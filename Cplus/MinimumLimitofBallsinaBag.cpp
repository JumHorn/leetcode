#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int minimumSize(vector<int> &nums, int maxOperations)
	{
		int lo = 1, hi = *max_element(nums.begin(), nums.end());
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			if (!canDivide(nums, mi, maxOperations))
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo;
	}

	bool canDivide(vector<int> &nums, int limit, int operation)
	{
		for (auto n : nums)
		{
			if ((n - 1) / limit > operation)
				return false;
			operation -= (n - 1) / limit;
		}
		return true;
	}
};