#include <vector>
using namespace std;

class Solution
{
public:
	int maxAbsoluteSum(vector<int> &nums)
	{
		int dp = 0, res = 0;
		for (auto n : nums)
		{
			dp = max(dp, 0) + n;
			res = max(res, dp);
		}
		dp = 0;
		for (auto n : nums)
		{
			dp = min(dp, 0) + n;
			res = max(res, -dp);
		}
		return res;
	}
};