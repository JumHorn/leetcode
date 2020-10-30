#include <ctype.h>
#include <stdlib.h>
#include <string.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	char *l = strstr(*(char **)lhs, " "), *r = strstr(*(char **)rhs, " ");
	int res = strcmp(l, r);
	if (res != 0)
		return res;
	*l = '\0';
	*r = '\0';
	res = strcmp(*(char **)lhs, *(char **)rhs);
	*l = ' ';
	*r = ' ';
	return res;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **reorderLogFiles(char **logs, int logsSize, int *returnSize)
{
	char *digitlog[logsSize], *letterlog[logsSize];
	int digitlogSize = 0, letterlogSize = 0;
	for (int i = 0; i < logsSize; ++i)
	{
		char *pos = strstr(logs[i], " ");
		if (isdigit(*(pos + 1)))
			digitlog[digitlogSize++] = logs[i];
		else
			letterlog[letterlogSize++] = logs[i];
	}
	char **res = (char **)malloc(sizeof(char *) * logsSize);
	*returnSize = 0;
	qsort(letterlog, letterlogSize, sizeof(char *), cmp);
	for (int i = 0; i < letterlogSize; ++i)
		res[(*returnSize)++] = strdup(letterlog[i]);
	for (int i = 0; i < digitlogSize; ++i)
		res[(*returnSize)++] = strdup(digitlog[i]);
	return res;
}