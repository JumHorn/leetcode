#include <stdlib.h>
#include <string.h>

void dfs(int n, int mismatch, int index, char *instance, char **res, int *resSize)
{
	if (index >= n)
	{
		if (mismatch == 0)
			res[(*resSize)++] = strdup(instance);
		return;
	}
	if (mismatch > 0)
	{
		instance[index] = ')';
		dfs(n, mismatch - 1, index + 1, instance, res, resSize);
	}
	instance[index] = '(';
	dfs(n, mismatch + 1, index + 1, instance, res, resSize);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **generateParenthesis(int n, int *returnSize)
{
	*returnSize = 0;
	char **res = (char **)malloc(sizeof(char *) * 2000);
	char instance[2 * n + 1];
	instance[2 * n] = '\0';
	dfs(2 * n, 0, 0, instance, res, returnSize);
	return res;
}