#include <limits.h>

double average(int* salary, int salarySize)
{
	int maxval = INT_MIN, minval = INT_MAX;
	int sum = 0;
	for (int i = 0; i < salarySize; ++i)
	{
		sum += salary[i];
		if (salary[i] > maxval)
			maxval = salary[i];
		if (salary[i] < minval)
			minval = salary[i];
	}
	return (sum - maxval - minval) * 1.0 / (salarySize - 2);
}
