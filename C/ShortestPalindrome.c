#include <stdlib.h>
#include <string.h>

int checkPalindrome(char *s, int index)
{
	for (int start = 0; start < index; ++start, --index)
	{
		if (s[start] != s[index])
			return 0;
	}
	return 1;
}

char *shortestPalindrome(char *s)
{
	if (!*s)
		return "";
	int n = strlen(s);
	int index = 1;
	for (int i = n - 1; i > 0; --i)
	{
		if (checkPalindrome(s, i) == 1)
		{
			index = i + 1;
			break;
		}
	}
	if (index == n)
		return s;
	char *res = (char *)malloc(sizeof(char) * (n + n - index + 1));
	for (int i = n - 1, j = 0; i >= index; i--, j++)
		res[j] = s[i];
	strcpy(&res[n - index], s);
	return res;
}
