#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* sampleStats(int* count, int countSize, int* returnSize)
{
	double minimum = 256, maximum = -1, mean = 0, median = 0, mode = 0;
	int N = countSize, size = 0;
	long sum = 0;
	for (int i = 0; i < N; ++i)
	{
		if (count[i] == 0)
			continue;
		//maximum minimum
		if (i > maximum)
			maximum = i;
		//minimum
		if (i < minimum)
			minimum = i;
		//sum
		sum += count[i] * i;
		//size
		size += count[i];
		//mode
		if (count[i] > count[(int)mode])
			mode = i;
	}
	//mean
	mean = sum * 1.0 / size;

	int prefixsum = 0, i = 0;
	for (i = 0; i < N && prefixsum * 2 < size; ++i)
		prefixsum += count[i];
	median = i - 1;
	if (size % 2 == 0 && prefixsum * 2 == size)
	{
		while (count[i] == 0)
			++i;
		median += i;
		median /= 2.0;
	}
	*returnSize = 5;
	double* res = (double*)malloc(sizeof(double) * (*returnSize));
	res[0] = minimum;
	res[1] = maximum;
	res[2] = mean;
	res[3] = median;
	res[4] = mode;
	return res;
}
