#include <string.h>

void reverse(char *arr, int first, int last)
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

char *reverseStr(char *s, int k)
{
	int N = strlen(s), i = 0;
	for (; i + k < N; i += 2 * k)
		reverse(s, i, i + k - 1);
	reverse(s, i, N - 1);
	return s;
}