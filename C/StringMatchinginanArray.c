#include <stdlib.h>
#include <string.h>

/**
 * wordsSizeote: The returned array must be malloced, assume caller calls free().
 */
char** stringMatching(char** words, int wordsSize, int* returnSize)
{
	char** res = (char**)malloc(sizeof(char*) * wordsSize);
	*returnSize = 0;
	for (int i = 0; i < wordsSize; ++i)
	{
		for (int j = 0; j < wordsSize; ++j)
		{
			if (i != j && strstr(words[j], words[i]) != NULL)
			{
				res[(*returnSize)++] = words[i];
				break;
			}
		}
	}
	return res;
}
