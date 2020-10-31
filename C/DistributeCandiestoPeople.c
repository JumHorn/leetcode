#include <stdlib.h>

int getFloor(int n)
{
	long lo = 0, hi = n;
	while (lo < hi)
	{
		long mi = (hi - lo) / 2 + lo;
		if (mi * (mi + 1) / 2 < n)
			lo = mi + 1;
		else
			hi = mi;
	}
	return lo - 1;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *distributeCandies(int candies, int num_people, int *returnSize)
{
	*returnSize = num_people;
	int *res = (int *)malloc(sizeof(int) * (*returnSize));
	int k = getFloor(candies);
	for (int i = 0; i < num_people; ++i)
	{
		res[i] = 0;
		for (int j = i + 1; j <= k; j += num_people)
			res[i] += j;
	}
	res[k % num_people] += candies - k * (k + 1) / 2;
	return res;
}