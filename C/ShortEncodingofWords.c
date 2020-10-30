#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *lhs, const void *rhs)
{
	return -strcmp(*(char **)lhs, *(char **)rhs); //des
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

bool startsWith(char *s, char *a)
{
	while (*a)
	{
		if (*s++ != *a++)
			return false;
	}
	return true;
}

int minimumLengthEncoding(char **words, int wordsSize)
{
	for (int i = 0; i < wordsSize; ++i)
		reverse(words[i], 0, strlen(words[i]) - 1);
	qsort(words, wordsSize, sizeof(char *), cmp);
	int res = strlen(words[0]) + 1;
	for (int i = 1, j = 0; i < wordsSize; ++i)
	{
		if (!startsWith(words[j], words[i]))
		{
			j = i;
			res += strlen(words[i]) + 1;
		}
	}
	return res;
}