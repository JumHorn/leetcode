#include <stdlib.h>
#include <string.h>

void reverse(char *arr, int first, int last)
{
	for (; first < last; ++first, --last)
	{
		char tmp = arr[first];
		arr[first] = arr[last];
		arr[last] = tmp;
	}
}

char *convertToBase7(int num)
{
	char *res = (char *)malloc(sizeof(char) * 20);
	int resSize = 0;
	if (num == 0)
		return "0";
	int sign = 1;
	if (num < 0)
	{
		num = -num;
		sign = -1;
	}
	while (num != 0)
	{
		res[resSize++] = num % 7 + '0';
		num /= 7;
	}
	if (sign == -1)
		res[resSize++] = '-';
	res[resSize] = '\0';
	reverse(res, 0, resSize - 1);
	return res;
}