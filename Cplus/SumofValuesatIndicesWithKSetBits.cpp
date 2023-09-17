#include <vector>
using namespace std;

class Solution
{
public:
	int sumIndicesWithKSetBits(vector<int> &nums, int k)
	{
		int res = 0, N = nums.size();
		for (int i = 0; i < N; ++i)
		{
			if (bitCount(i) == k)
				res += nums[i];
		}
		return res;
	}

	int bitCount(int n)
	{
		int res = 0;
		for (; n != 0; n &= n - 1)
			++res;
		return res;
	}
};