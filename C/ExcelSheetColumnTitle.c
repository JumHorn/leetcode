#include <stdlib.h>
#include <string.h>

void reverse(char* arr, int first, int last)
{
	while (first < last)
	{
		char tmp = arr[first];
		arr[first] = arr[last];
		arr[last] = tmp;
		++first;
		--last;
	}
}

char* convertToTitle(int n)
{
	char* res = (char*)malloc(sizeof(char) * 100);
	int resSize = 0;
	while (n != 0)
	{
		res[resSize++] = (n - 1) % 26 + 'A';
		n = (n - 1) / 26;
	}
	reverse(res, 0, resSize - 1);
	res[resSize] = '\0';
	return res;
}
