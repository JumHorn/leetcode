#include <stdbool.h>

bool complete(int *gas, int gasSize, int *cost, int index)
{
	int leftgas = gas[index] - cost[index], i;
	for (i = (index + 1) % gasSize; leftgas >= 0 && i != index; i = (i + 1) % gasSize)
		leftgas += gas[i] - cost[i];
	return leftgas >= 0 && i == index;
}

int canCompleteCircuit(int *gas, int gasSize, int *cost, int costSize)
{
	for (int i = 0; i < gasSize; ++i)
	{
		if (complete(gas, gasSize, cost, i))
			return i;
	}
	return -1;
}