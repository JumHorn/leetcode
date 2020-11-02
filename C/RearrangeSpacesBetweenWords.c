#include <string.h>

char *reorderSpaces(char *text)
{
	int space = 0, N = 0, resSize = 0, wordSize = 0;
	for (; text[N]; ++N)
	{
		if (text[N] == ' ')
			++space;
	}
	char *res = (char *)malloc(sizeof(char) * (N + 1));
	char **word = (char **)malloc(sizeof(char *) * N);
	res[N] = '\0';
	for (char *token = strtok(text, " "); token; token = strtok(NULL, " "))
		word[wordSize++] = token;
	if (wordSize == 1)
	{
		resSize += sprintf(res, "%s", word[0]);
		memset(&res[resSize], ' ', sizeof(char) * (N - resSize));
		return res;
	}
	int n = space / (wordSize - 1);
	space %= wordSize - 1;
	resSize += sprintf(res, "%s", word[0]);
	for (int i = 1; i < wordSize; ++i)
	{
		memset(&res[resSize], ' ', sizeof(char) * n);
		resSize += n;
		resSize += sprintf(&res[resSize], word[i]);
	}
	memset(&res[resSize], ' ', sizeof(char) * space);
	return res;
}