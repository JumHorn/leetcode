#include <vector>
using namespace std;

class Solution
{
public:
	int longestSubarray(vector<int> &nums)
	{
		int d0 = 0, d1 = -1, res = 0;
		for (auto n : nums)
		{
			if (n == 0)
			{
				d1 = d0;
				d0 = 0;
			}
			else
			{
				d1 = max(d1 + 1, d0);
				d0 = d0 + 1;
			}
			res = max(res, d1);
		}
		return res;
	}
};