#include <stdbool.h>

int canCompleteCircuit(int *gas, int gasSize, int *cost, int costSize)
{
	int minus = 0, leftgas = 0, res = 0;
	for (int i = 0; i < gasSize; ++i)
	{
		leftgas += gas[i] - cost[i];
		if (leftgas < 0)
		{
			res = i + 1;
			minus += leftgas;
			leftgas = 0;
		}
	}
	return minus + leftgas < 0 ? -1 : res;
}