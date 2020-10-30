#include <stdbool.h>

bool alienCmp(char *lhs, char *rhs, int *hash)
{
	for (; *lhs && *rhs; ++lhs, ++rhs)
	{
		if (*lhs != *rhs)
			return hash[*lhs - 'a'] < hash[*rhs - 'a'];
	}
	return !*lhs;
}

bool isAlienSorted(char **words, int wordsSize, char *order)
{
	int hash[26] = {0};
	for (int i = 0; order[i]; ++i)
		hash[order[i] - 'a'] = i;
	for (int i = 0; i < wordsSize - 1; ++i)
	{
		if (!alienCmp(words[i], words[i + 1], hash))
			return false;
	}
	return true;
}