#include <vector>
using namespace std;

class Solution
{
public:
	bool xorGame(vector<int> &nums)
	{
		int XOR = 0;
		for (auto n : nums)
			XOR ^= n;
		return XOR == 0 || nums.size() % 2 == 0;
	}
};