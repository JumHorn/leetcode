#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	int maximumLength(vector<int> &nums)
	{
		int odd = 0, even = 0, oddeven = 0, r = nums[0] % 2;
		for (auto n : nums)
		{
			if (n % 2 == 0)
				++even;
			else
				++odd;
			if (n % 2 == r)
			{
				++oddeven;
				r = 1 - r;
			}
		}
		return max({odd, even, oddeven});
	}
};