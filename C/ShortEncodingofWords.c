#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define swap(a, b) ((a) ^= (b) ^= (a) ^= (b))

int cmp(const void *lhs, const void *rhs)
{
	return -strcmp(*(char **)lhs, *(char **)rhs);  //des
}

void reverse(char *s)
{
	int i = 0, j = strlen(s) - 1;
	while (i < j)
	{
		swap(s[i], s[j]);
		++i;
		--j;
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
		reverse(words[i]);
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
