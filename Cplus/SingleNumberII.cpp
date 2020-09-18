#include <vector>
using namespace std;

/*
count every bit int the array
if the sum is not a multiple of 3
the bit in the result should be 1
*/

class Solution
{
public:
	int singleNumber(vector<int> &nums)
	{
		int res = 0;
		for (int i = 0; i < 32; ++i)
		{
			int count = 0;
			for (auto n : nums)
				count += (n >> i) & 0x01;
			if (count % 3 != 0)
				res |= 1u << i;
		}
		return res;
	}
};