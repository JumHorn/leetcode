#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> singleNumber(vector<int> &nums)
	{
		int XOR = 0;
		for (auto n : nums)
			XOR ^= n;
		int rightmostbit = (XOR & -XOR);
		int a = 0, b = 0;
		for (auto n : nums)
		{
			if (n & rightmostbit)
				a ^= n;
			else
				b ^= n;
		}
		return {a, b};
	}
};