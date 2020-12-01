#include <stdlib.h>
#include <string.h>

void dfs(char **map, char *digits, int index, char *instance, char (*res)[20], int *resSize)
{
	if (!*digits)
	{
		strcpy(res[*resSize], instance);
		++*resSize;
		return;
	}
	for (char *p = map[*digits - '0']; *p; ++p)
	{
		instance[index] = *p;
		dfs(map, digits + 1, index + 1, instance, res, resSize);
	}
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **letterCombinations(char *digits, int *returnSize)
{
	static char staticRes[1024][20];
	char *map[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	*returnSize = 0;
	int N = strlen(digits);
	if (!*digits)
		return NULL;
	char instance[N + 1];
	instance[N] = '\0';
	dfs(map, digits, 0, instance, staticRes, returnSize);

	char **res = (char **)malloc(sizeof(char *) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
		res[i] = strdup(staticRes[i]);
	return res;
}