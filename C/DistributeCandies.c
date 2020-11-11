#include <limits.h>
#include <stdlib.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

int distributeCandies(int *candies, int candiesSize)
{
	qsort(candies, candiesSize, sizeof(int), cmp);
	int type = 0, pre = INT_MIN;
	for (int i = 0; i < candiesSize && type < candiesSize / 2; ++i)
	{
		if (candies[i] != pre)
		{
			pre = candies[i];
			++type;
		}
	}
	return type <= candiesSize / 2 ? type : candiesSize / 2;
}