#include <vector>
using namespace std;

class Solution
{
public:
	int minOrAfterOperations(vector<int> &nums, int k)
	{
		int res = 0, mask = 0;
		for (int i = 30; i >= 0; --i)
		{
			int count = 0, allmask = -1; // all bit set
			mask ^= 1 << i;
			for (auto n : nums)
			{
				allmask &= (n & mask);
				if (allmask != 0)
					++count;
				else
					allmask = -1;
			}
			if (count > k)
			{
				res ^= 1 << i;
				mask ^= 1 << i;
			}
		}
		return res;
	}
};