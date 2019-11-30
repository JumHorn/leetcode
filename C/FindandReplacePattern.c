#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** findAndReplacePattern(char** words, int wordsSize, char* pattern, int* returnSize)
{
	int* index = (int*)malloc(sizeof(int) * wordsSize);
	memset(index, -1, sizeof(sizeof(int) * wordsSize));
	*returnSize = 0;
	int len = strlen(pattern);
	for (int i = 0, j = 0; i < wordsSize; i++)
	{
		char mapw[26] = {0}, mapp[26] = {0}, *w = words[i], *p = pattern;
		while (*w && *p)
		{
			if (mapw[*w - 'a'] == 0)
			{
				if (mapp[*p - 'a'] != 0)
					break;
				mapw[*w - 'a'] = *p;
				mapp[*p - 'a'] = *w;
			}
			else
			{
				if (mapw[*w - 'a'] != *p)
					break;
			}
			p++;
			w++;
		}
		if (!*p && !*w)
		{
			++(*returnSize);
			index[j++] = i;
		}
	}

	if (*returnSize == 0)
		return NULL;
	char** res = (char**)malloc(sizeof(char*) * (*returnSize));
	for (int i = 0; i < *returnSize; i++)
	{
		res[i] = (char*)malloc(sizeof(char) * (len + 1));
		memcpy(res[i], words[index[i]], len + 1);
	}
	return res;
}

