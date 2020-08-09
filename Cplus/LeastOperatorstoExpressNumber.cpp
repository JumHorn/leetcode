#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	int leastOpsExpressTarget(int x, int target)
	{
		unordered_map<long, long> cache;
		return recursive(x, target, cache);
	}

	int recursive(int x, int target, unordered_map<long, long> &cache)
	{
		if (target == 0)
			return 0;
		if (target == 1)
			return 1;
		if (x == target)
			return 0;
		if (x > target)
			return min(target * 2 - 1, (x - target) * 2);
		if (cache.find(target) != cache.end())
			return cache[target];
		long val = 1, count = 0;
		while (val < target)
		{
			val *= x;
			++count;
		}
		if (val == target)
			return count - 1;
		int res1 = INT_MAX, res2 = INT_MAX;
		if (val - target < target)
			res1 = recursive(x, val - target, cache) + count;
		res2 = recursive(x, target - val / x, cache) + count - 1;
		return cache[target] = min(res1, res2);
	}
};