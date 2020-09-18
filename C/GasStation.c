#include <stdbool.h>

/*
If car starts at A and can not reach B. Any station between A and B
can not reach B.(B is the first station that A can not reach.)
*/

int canCompleteCircuit(int *gas, int gasSize, int *cost, int costSize)
{
	for (int i = 0; i < gasSize;)
	{
		int leftgas = gas[i] - cost[i], j;
		for (j = (i + 1) % gasSize; leftgas >= 0 && j != i; j = (j + 1) % gasSize)
			leftgas += gas[j] - cost[j];
		if (leftgas >= 0 && j == i)
			return i;
		if (j <= i)
			break;
		i = j;
	}
	return -1;
}