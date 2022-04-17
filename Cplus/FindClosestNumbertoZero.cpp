#include <vector>
using namespace std;

class Solution
{
public:
	int findClosestNumber(vector<int> &nums)
	{
		int res = INT_MIN + 1;
		for (auto n : nums)
		{
			if (abs(n) < abs(res) || (abs(n) == abs(res) && n > res))
				res = n;
		}
		return res;
	}
};