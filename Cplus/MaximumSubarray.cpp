#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

//Kadane's Algorithm

class Solution
{
public:
	int maxSubArray(vector<int> &nums)
	{
		int dp = INT_MIN, res = INT_MIN;
		for (auto n : nums)
		{
			dp = max(dp, 0) + n;
			res = max(res, dp);
		}
		return res;
	}
};