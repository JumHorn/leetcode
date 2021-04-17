#include <vector>
using namespace std;

class Solution
{
public:
	int minOperations(vector<int> &nums)
	{
		int pre = nums[0] - 1, res = 0;
		for (auto n : nums)
		{
			if (n <= pre)
			{
				res += pre - n + 1;
				++pre;
			}
			else
				pre = n;
		}
		return res;
	}
};