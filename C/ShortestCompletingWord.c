#include <ctype.h>
#include <stdbool.h>
#include <string.h>

void countAlpha(char *word, int *hash)
{
	for (int i = 0; word[i]; ++i)
	{
		if (isalpha(word[i]))
			++hash[tolower(word[i]) - 'a'];
	}
}

bool contains(int *lhs, int *rhs)  //rhs constain lhs
{
	for (int i = 0; i < 26; ++i)
	{
		if (lhs[i] > rhs[i])
			return false;
	}
	return true;
}

char *shortestCompletingWord(char *licensePlate, char **words, int wordsSize)
{
	char *res = NULL;
	int hash[26] = {0};
	countAlpha(licensePlate, hash);
	for (int i = 0; i < wordsSize; ++i)
	{
		int map[26] = {0};
		countAlpha(words[i], map);
		if (contains(hash, map) && (!res || strlen(res) > strlen(words[i])))
			res = words[i];
	}
	return res;
}
