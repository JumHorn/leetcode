#include <string.h>

#define swap(a, b) ((a) ^= (b) ^= (a) ^= (b))

void trim(char *s)
{
	int space = 1;
	char *p = s, *q = s;
	while (*p)
	{
		if (*p != ' ' || space == 0)
		{
			*q++ = *p;
			space = (*p == ' ' ? 1 : 0);
		}
		++p;
	}
	if (q != s && *(q - 1) == ' ')
		--q;
	*q = '\0';
}

void reverse(char *arr, int first, int last)
{
	for (; first < last; ++first, --last)
	{
		char tmp = arr[first];
		arr[first] = arr[last];
		arr[last] = tmp;
	}
}

char *reverseWords(char *s)
{
	trim(s);
	int N = strlen(s);
	reverse(s, 0, N - 1);
	for (int i = 0, j = 0; i < N; i = j)
	{
		while (s[i] && s[i] != ' ')
			++i;
		reverse(s, j, i - 1);
		j = i + 1;
	}
	return s;
}