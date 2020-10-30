#include <stdlib.h>
#include <string.h>

/*
Convert a number into negative base representation
https://www.geeksforgeeks.org/convert-number-negative-base-representation/
any negative number can be a base
I should use math fomular to solve this problem
most important thing to remember is, remainder will always be positive
*/

void reverse(char *arr, int first, int last)
{
	for (; first < last; ++first, --last)
	{
		char tmp = arr[first];
		arr[first] = arr[last];
		arr[last] = tmp;
	}
}

char *baseNeg2(int N)
{
	char *res = (char *)malloc(sizeof(char) * 40);
	int resSize = 0;
	while (N != 0)
	{
		res[resSize++] = (N & 1) + '0';
		N = -(N >> 1);
	}
	res[resSize] = '\0';
	reverse(res, 0, resSize - 1);
	return resSize == 0 ? "0" : res;
}