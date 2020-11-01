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

char* freqAlphabets(char* s)
{
	char* res = (char*)malloc(sizeof(char) * 1000);
	int resSize = 0;
	for (int i = strlen(s) - 1; i >= 0; --i)
	{
		char c;
		if (s[i] == '#')
		{
			c = (s[i - 1] - '0') + (s[i - 2] - '0') * 10 - 10 + 'j';
			i -= 2;
		}
		else
			c = s[i] - '0' - 1 + 'a';
		res[resSize++] = c;
	}
	res[resSize] = '\0';
	reverse(res, 0, resSize - 1);
	return res;
}
