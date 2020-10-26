#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **printVertically(char *s, int *returnSize)
{
	char *word[200] = {0};
	int wordSize = 0, maxWordLen = 0;
	for (char *token = strtok(s, " "); token; token = strtok(NULL, " "))
	{
		word[wordSize++] = token;
		int len = strlen(token);
		maxWordLen = max(maxWordLen, len);
	}

	*returnSize = maxWordLen;
	char **res = (char **)malloc(sizeof(char *) * (*returnSize));
	for (int j = 0; j < maxWordLen; ++j)
	{
		res[j] = (char *)malloc(sizeof(char) * (wordSize + 1));
		int index = 0;
		for (int i = 0; i < wordSize; ++i)
		{
			if (*word[i])
				res[j][index++] = *word[i]++;
			else
				res[j][index++] = ' ';
		}
		while (index > 0 && res[j][index - 1] == ' ')
			--index;
		res[j][index] = '\0';
	}
	return res;
}