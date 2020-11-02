#include <stdlib.h>
#include <string.h>

void reverse(char* arr, int first, int last)
{
	for (; first < last; ++first, --last)
	{
		char tmp = arr[first];
		arr[first] = arr[last];
		arr[last] = tmp;
	}
}

char* thousandSeparator(int n)
{
	if (n == 0)
		return "0";
	char* res = (char*)malloc(sizeof(char) * 15);
	int count = 0, resSize = 0;
	while (n != 0)
	{
		res[resSize++] = n % 10 + '0';
		n /= 10;
		if (++count == 3 && n != 0)
		{
			count = 0;
			res[resSize++] = '.';
		}
	}
	res[resSize] = '\0';
	reverse(res, 0, resSize - 1);
	return res;
}
