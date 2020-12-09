#include <string.h>

void trim(char *s)
{
	int space = 1, top = -1;
	for (int i = 0; s[i]; ++i)
	{
		if (s[i] != ' ' || space == 0)
		{
			s[++top] = s[i];
			space = (s[i] == ' ' ? 1 : 0);
		}
	}
	if (top >= 0 && s[top] == ' ')
		--top;
	s[top + 1] = '\0';
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
		reverse(s, j, i - 1); //reverse single word
		j = i + 1;
	}
	return s;
}