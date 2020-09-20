#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *lhs, const void *rhs)
{
	char *l = (char *)lhs, *r = (char *)rhs;
	while (*l && *r)
	{
		if (*l != *r)
			return *r - *l;
		++l;
		++r;
	}
	if (!*l && !*r)
		return 0;
	if (*l)
	{
		char *p = (char *)lhs;
		while (*l && *l == *p)
		{
			++l;
			++p;
		}
		return *p - *l;
	}
	char *p = (char *)rhs;
	while (*r && *r == *p)
	{
		++r;
		++p;
	}
	return *r - *p;
}

char *largestNumber(int *nums, int numsSize)
{
	char digits[numsSize][10];
	for (int i = 0; i < numsSize; ++i)
		sprintf(digits[i], "%d", nums[i]);
	qsort(digits, numsSize, sizeof(digits[0]), cmp);
	char *res = (char *)malloc(sizeof(char) * 1000);
	res[0] = '\0';
	for (int i = 0; i < numsSize; ++i)
		strcat(res, digits[i]);
	if (res[0] == '0')
		res[1] = '\0';
	return res;
}