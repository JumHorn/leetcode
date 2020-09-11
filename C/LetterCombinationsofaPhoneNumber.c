#include <stdlib.h>
#include <string.h>

void dfs(char **map, char *digits, char *data, int index, int *size, char (*res)[20])
{
	if (!*digits)
	{
		strcpy(res[*size], data);
		++*size;
		return;
	}
	for (char *p = map[*digits - '0']; *p; ++p)
	{
		data[index] = *p;
		dfs(map, digits + 1, data, index + 1, size, res);
	}
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **letterCombinations(char *digits, int *returnSize)
{
	static char staticRes[10000][20];
	char *map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	*returnSize = 0;
	int N = strlen(digits);
	if (!*digits)
		return NULL;
	char data[N + 1];
	data[N] = '\0';
	dfs(map, digits, data, 0, returnSize, staticRes);

	char **res = (char **)malloc(sizeof(char *) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
	{
		res[i] = (char *)malloc(sizeof(char) * (N + 1));
		strcpy(res[i], staticRes[i]);
	}
	return res;
}