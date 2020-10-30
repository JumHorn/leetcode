#include <stdlib.h>
#include <string.h>

int cmp(const void *lhs, const void *rhs)
{
	return strcmp(*(char **)lhs, *(char **)rhs);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **uncommonFromSentences(char *A, char *B, int *returnSize)
{
	char *arr[500];
	int arrSize = 0;
	for (char *token = strtok(A, " "); token; token = strtok(NULL, " "))
		arr[arrSize++] = token;
	for (char *token = strtok(B, " "); token; token = strtok(NULL, " "))
		arr[arrSize++] = token;
	qsort(arr, arrSize, sizeof(char *), cmp);
	char **res = (char **)malloc(sizeof(char *) * arrSize);
	*returnSize = 0;
	for (int i = 1, j = 0; i <= arrSize; ++i)
	{
		if (i == arrSize || strcmp(arr[i], arr[j]) != 0)
		{
			if (i - j == 1)
				res[(*returnSize)++] = strdup(arr[j]);
			j = i;
		}
	}
	return res;
}