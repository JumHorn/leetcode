#include <vector>
using namespace std;

class Solution
{
public:
	bool xorGame(vector<int> &nums)
	{
		int XOR = 0;
		for (int i = 0; i < (int)nums.size(); i++)
			XOR ^= nums[i];
		return XOR == 0 || nums.size() % 2 == 0;
	}
};