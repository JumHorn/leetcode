#include <stdbool.h>
#include <string.h>

int recursive(char *text, int left, int right)
{
	if (left >= right)
		return 0;
	for (int i = right - 1; left + right - i <= i; --i)
	{
		if (text[left] == text[i] && strncmp(&text[left], &text[i], right - i) == 0)
			return 2 + recursive(text, left + right - i, i);
	}
	return 1;
}

int longestDecomposition(char *text)
{
	int len = strlen(text);
	return recursive(text, 0, len);
}