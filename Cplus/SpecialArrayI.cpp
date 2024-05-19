#include <vector>
using namespace std;

class Solution
{
public:
	bool isArraySpecial(vector<int> &nums)
	{
		int pre = 1 - nums[0] % 2;
		for (auto n : nums)
		{
			if (pre % 2 == n % 2)
				return false;
			pre = n;
		}
		return true;
	}
};