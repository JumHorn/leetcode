#include <vector>
using namespace std;

class Solution
{
public:
	int minOperations(vector<int> &nums)
	{
		int res = 0, maxbit = 1;
		for (auto &n : nums)
		{
			int bits = 0;
			while (n > 0)
			{
				res += n & 1;
				++bits;
				n >>= 1;
			}
			maxbit = max(maxbit, bits);
		}
		return res + maxbit - 1;
	}
};