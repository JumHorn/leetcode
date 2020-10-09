#include <ctype.h>
#include <stdlib.h>
#include <string.h>

//malloc result
char **mallocRes(char (*data)[15], int dataSize, int *returnSize)
{
	*returnSize = dataSize;
	char **res = (char **)malloc(sizeof(char *) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
	{
		int n = strlen(data[i]);
		res[i] = (char *)malloc(sizeof(char) * (n + 1));
		strcpy(res[i], data[i]);
	}
	return res;
}

void addOneResult(char (*staticRes)[15], int *size, char *instance)
{
	strcpy(staticRes[(*size)++], instance);
}

void dfs(char *s, int index, char (*staticRes)[15], int *size)
{
	if (!s[index])
	{
		addOneResult(staticRes, size, s);
		return;
	}
	if (!isalpha(s[index]))
		return dfs(s, index + 1, staticRes, size);
	char old = s[index];
	s[index] = tolower(s[index]);
	dfs(s, index + 1, staticRes, size);
	s[index] = toupper(s[index]);
	dfs(s, index + 1, staticRes, size);
	s[index] = old;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **letterCasePermutation(char *S, int *returnSize)
{
	static char staticRes[5000][15];
	*returnSize = 0;
	dfs(S, 0, staticRes, returnSize);
	return mallocRes(staticRes, *returnSize, returnSize);
}