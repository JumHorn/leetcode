#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *lhs, const void *rhs)
{
	static char arr1[30], arr2[30];
	char *l = (char *)lhs, *r = (char *)rhs;
	sprintf(arr1, "%s%s", l, r);
	sprintf(arr2, "%s%s", r, l);
	return strcmp(arr2, arr1);
}

char *largestNumber(int *nums, int numsSize)
{
	char digits[numsSize][10];
	for (int i = 0; i < numsSize; ++i)
		sprintf(digits[i], "%d", nums[i]);
	qsort(digits, numsSize, sizeof(digits[0]), cmp);
	char *res = (char *)malloc(sizeof(char) * 1000);
	res[0] = '\0';
	for (int i = 0, resSize = 0; i < numsSize; ++i)
		resSize += sprintf(&res[resSize], "%s", digits[i]);
	if (res[0] == '0')
		res[1] = '\0';
	return res;
}