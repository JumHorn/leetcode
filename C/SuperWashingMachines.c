#include <math.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int findMinMoves(int *machines, int machinesSize)
{
	int sum = 0;
	for (int i = 0; i < machinesSize; ++i)
		sum += machines[i];
	if (sum % machinesSize != 0)
		return -1;
	int avg = sum / machinesSize;
	for (int i = 0; i < machinesSize; ++i)
		machines[i] -= avg;
	int res = 0, count = 0;
	for (int i = 0; i < machinesSize; ++i)
	{
		count += machines[i];
		res = max(res, max(abs(count), machines[i]));
	}
	return res;
}