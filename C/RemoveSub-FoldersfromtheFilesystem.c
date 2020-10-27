#include <stdlib.h>
#include <string.h>

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return strcmp(*(char **)lhs, *(char **)rhs);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **removeSubfolders(char **folder, int folderSize, int *returnSize)
{
	*returnSize = 0;
	qsort(folder, folderSize, sizeof(char *), cmp);
	for (int i = 0; i < folderSize; ++i)
	{
		if (*returnSize == 0 ||
			strncmp(folder[*returnSize - 1], folder[i], strlen(folder[*returnSize - 1])) != 0 ||
			folder[i][strlen(folder[*returnSize - 1])] != '/')
			folder[(*returnSize)++] = folder[i];
	}
	char **res = (char **)malloc(sizeof(char *) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
		res[i] = strdup(folder[i]);
	return res;
}