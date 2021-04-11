#include <vector>
using namespace std;

class Solution
{
public:
	int arraySign(vector<int> &nums)
	{
		int res = 1;
		for (auto n : nums)
		{
			if (n == 0)
				return 0;
			if (n < 0)
				res = -res;
		}
		return res;
	}
};