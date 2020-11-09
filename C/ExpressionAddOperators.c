#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dfs(char *num, int index, int target, long cur, long pre, char *instance, int instanceSize, char **res, int *resSize)
{
	if (!num[index])
	{
		if (cur == target)
			res[(*resSize)++] = strdup(instance);
		return;
	}
	char sub[30] = {0};
	int subSize = 0;
	for (int i = index; num[i]; ++i)
	{
		sub[subSize++] = num[i];
		long n = atol(sub);
		if (index == 0)
		{
			instanceSize = sprintf(instance, "%s", sub);
			dfs(num, i + 1, target, n, n, instance, instanceSize, res, resSize);
		}
		else
		{
			int size = sprintf(&instance[instanceSize], "+%s", sub) + instanceSize;
			dfs(num, i + 1, target, cur + n, n, instance, size, res, resSize);
			size = sprintf(&instance[instanceSize], "-%s", sub) + instanceSize;
			dfs(num, i + 1, target, cur - n, -n, instance, size, res, resSize);
			size = sprintf(&instance[instanceSize], "*%s", sub) + instanceSize;
			dfs(num, i + 1, target, cur - pre + n * pre, n * pre, instance, size, res, resSize);
		}
		if (num[index] == '0')
			break;
	}
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **addOperators(char *num, int target, int *returnSize)
{
	char **res = (char **)malloc(sizeof(char *) * 5000);
	char instance[30] = {0};
	*returnSize = 0;
	dfs(num, 0, target, 0, 0, instance, 0, res, returnSize);
	return res;
}