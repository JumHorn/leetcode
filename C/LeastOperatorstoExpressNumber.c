#include <limits.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

int leastOpsExpressTarget(int x, int target)
{
	if (target == 0)
		return 0;
	if (target == 1)
		return 1;
	if (x == target)
		return 0;
	if (x > target)
		return min(target * 2 - 1, (x - target) * 2);
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
		res1 = leastOpsExpressTarget(x, val - target) + count;
	res2 = leastOpsExpressTarget(x, target - val / x) + count - 1;
	return min(res1, res2);
}