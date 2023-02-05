#include <vector>
using namespace std;

class Solution
{
public:
	int minCapability(vector<int> &nums, int k)
	{
		int lo = 1, hi = 1e9 + 1;
		while (lo < hi)
		{
			int mi = (hi - lo) / 2 + lo;
			int count = rob(nums, mi);
			if (count < k)
				lo = mi + 1;
			else
				hi = mi;
		}
		return lo;
	}

	int rob(vector<int> &nums, int cap)
	{
		int f0 = 0, f1 = 0;
		for (auto n : nums)
		{
			if (n <= cap)
			{
				int f2 = f0;
				f0 = f1;
				f1 = max(f1, f2 + 1);
			}
			else
				f0 = f1;
		}
		return f1;
	}
};