#include <stdlib.h>
#include <string.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

typedef struct Anagrams
{
	char *str;
	int index;
} Anagrams;

int anagramsCmp(const void *lhs, const void *rhs)
{
	return strcmp(((Anagrams *)lhs)->str, ((Anagrams *)rhs)->str);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char ***groupAnagrams(char **strs, int strsSize, int *returnSize, int **returnColumnSizes)
{
	static char staticRes[10001][1001][101];
	static int staticResColSize[10001];
	memset(staticResColSize, 0, sizeof(staticResColSize));
	Anagrams anagrams[strsSize];
	for (int i = 0; i < strsSize; ++i)
	{
		int n = strlen(strs[i]);
		anagrams[i].index = i;
		anagrams[i].str = (char *)malloc(sizeof(char) * (n + 1));
		strcpy(anagrams[i].str, strs[i]);
		qsort(anagrams[i].str, n, sizeof(char), cmp);
	}
	qsort(anagrams, strsSize, sizeof(Anagrams), anagramsCmp);
	int size = -1;
	for (int i = 0; i < strsSize; ++i)
	{
		if (i == 0 || strcmp(anagrams[i].str, anagrams[i - 1].str) != 0)
			strcpy(staticRes[++size][staticResColSize[size]++], strs[anagrams[i].index]);
		else
			strcpy(staticRes[size][staticResColSize[size]++], strs[anagrams[i].index]);
	}

	*returnSize = size + 1;
	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	memcpy(*returnColumnSizes, staticResColSize, sizeof(int) * (*returnSize));
	char ***res = (char ***)malloc(sizeof(char **) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
	{
		res[i] = (char **)malloc(sizeof(char *) * (*returnColumnSizes)[i]);
		for (int j = 0; j < (*returnColumnSizes)[i]; ++j)
		{
			int n = strlen(staticRes[i][j]);
			res[i][j] = (char *)malloc(sizeof(char) * (n + 1));
			strcpy(res[i][j], staticRes[i][j]);
		}
	}
	return res;
}