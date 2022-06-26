#include <vector>
using namespace std;

class Solution
{
public:
	int maximumXOR(vector<int> &nums)
	{
		int res = 0;
		for (int i = 0; i < 31; ++i)
		{
			int count = 0;
			for (auto n : nums)
			{
				if ((n >> i) & 1)
				{
					count = 1;
					break;
				}
			}
			if (count == 1)
				res |= 1 << i;
		}
		return res;
	}
};