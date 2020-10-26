#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool all_of(char *word, int *hash, int row)
{
	while (*word)
	{
		if (hash[toupper(*word) - 'A'] != row)
			return false;
		++word;
	}
	return true;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **findWords(char **words, int wordsSize, int *returnSize)
{
	char **res = (char **)malloc(sizeof(char *) * wordsSize);
	*returnSize = 0;
	char *rows[] = {"QWERTYUIOP", "ASDFGHJKL", "ZXCVBNM"};
	int hash[26] = {0}; //{char,row}
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; rows[i][j]; ++j)
			hash[rows[i][j] - 'A'] = i;
	}
	for (int i = 0; i < wordsSize; ++i)
	{
		if (all_of(words[i], hash, 0) || all_of(words[i], hash, 1) || all_of(words[i], hash, 2))
		{
			int len = strlen(words[i]);
			res[*returnSize] = (char *)malloc(sizeof(char *) * (len + 1));
			strcpy(res[(*returnSize)++], words[i]);
		}
	}
	return res;
}