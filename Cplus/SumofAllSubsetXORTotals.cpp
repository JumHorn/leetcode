#include <vector>
using namespace std;

class Solution
{
public:
	int subsetXORSum(vector<int> &nums)
	{
		int res = 0, N = nums.size();
		for (int mask = (1 << N) - 1; mask > 0; --mask)
		{
			int x = 0;
			for (int i = 0; i < N; ++i)
			{
				if ((1 << i) & mask)
					x ^= nums[i];
			}
			res += x;
		}
		return res;
	}
};