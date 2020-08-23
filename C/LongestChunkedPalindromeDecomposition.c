#include <stdbool.h>
#include <string.h>

bool checkValid(char *text, int left, int right, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (text[left + i] != text[right + i])
			return false;
	}
	return true;
}

int recursive(char *text, int left, int right)
{
	if (left >= right)
		return 0;
	for (int i = right - 1; left + right - i <= i; --i)
	{
		if (text[left] == text[i] && checkValid(text, left, i, right - i))
			return 2 + recursive(text, left + right - i, i);
	}
	return 1;
}

int longestDecomposition(char *text)
{
	int len = strlen(text);
	return recursive(text, 0, len);
}