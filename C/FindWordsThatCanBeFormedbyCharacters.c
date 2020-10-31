#include <stdbool.h>

bool arrLessThan(int *map, int *hash, int size)
{
	for (int i = 0; i < size; ++i)
	{
		if (map[i] < hash[i])
			return false;
	}
	return true;
}

int countCharacters(char **words, int wordsSize, char *chars)
{
	int map[26] = {0}, res = 0;
	while (*chars)
		++map[*chars++ - 'a'];
	for (int i = 0; i < wordsSize; ++i)
	{
		int hash[26] = {0}, len = 0;
		for (char *p = words[i]; *p; ++p)
		{
			++len;
			++hash[*p - 'a'];
		}
		if (arrLessThan(map, hash, 26))
			res += len;
	}
	return res;
}