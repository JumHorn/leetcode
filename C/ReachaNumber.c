#include <stdbool.h>

int reachNumber(int target)
{
	int sum = 0, steps = 1;
	if (target < 0)
		target = -target;
	while (true)
	{
		sum += steps;
		if (sum == target)
			return steps;
		if (sum > target)
			break;
		++steps;
	}
	if ((sum - target) % 2 == 0)
		return steps;
	return steps + 1 + steps % 2;
}