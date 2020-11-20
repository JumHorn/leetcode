#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	int leastOpsExpressTarget(int x, int target)
	{
		unordered_map<long, long> dp;
		return memdp(x, target, dp);
	}

	int memdp(int x, int target, unordered_map<long, long> &dp)
	{
		if (target < 2)
			return target;
		if (x == target)
			return 0;
		if (x > target)
			return min(target * 2 - 1, (x - target) * 2);
		if (dp.find(target) != dp.end())
			return dp[target];
		long val = 1, count = 0;
		for (; val < target; val *= x)
			++count;
		if (val == target)
			return count - 1;
		int res1 = INT_MAX, res2 = INT_MAX;
		if (val - target < target)
			res1 = memdp(x, val - target, dp) + count;
		res2 = memdp(x, target - val / x, dp) + count - 1;
		return dp[target] = min(res1, res2);
	}
};