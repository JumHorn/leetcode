#include <stdlib.h>

int cmp(const void* lhs, const void* rhs)
{
	return *(int*)lhs - *(int*)rhs;
}

int numFriendRequests(int* ages, int agesSize)
{
	qsort(ages, agesSize, sizeof(int), cmp);
	int res = 0;
	for (int i = 0, j = 1; i < agesSize; i++)
	{
		if (i == j)
			j++;
		while (j < agesSize && ages[j] * 0.5 + 7 < ages[i])
		{
			res += j - i;
			j++;
		}
	}
	for (int i = 0, j = 1; i < agesSize;)
	{
		j = i + 1;
		while (j < agesSize && ages[i] == ages[j])
			j++;
		if (j - i != 1 && ages[i] * 0.5 + 7 < ages[i])
			res += (j - i) * (j - i - 1) / 2;
		i = j;
	}
	return res;
}

