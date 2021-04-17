#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
	{
		vector<int> res;
		int mask = (1 << maximumBit) - 1, XOR = 0;
		for (auto n : nums)
		{
			XOR ^= n;
			res.push_back((~XOR & mask));
		}
		reverse(res.begin(), res.end());
		return res;
	}
};