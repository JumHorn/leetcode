#include <stdlib.h>
#include <string.h>

//char cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(char *)lhs == *(char *)rhs)
		return 0;
	return *(char *)lhs < *(char *)rhs ? -1 : 1;
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
	Anagrams anagrams[strsSize];
	for (int i = 0; i < strsSize; ++i)
	{
		int n = strlen(strs[i]);
		anagrams[i].index = i;
		anagrams[i].str = strdup(strs[i]);
		qsort(anagrams[i].str, n, sizeof(char), cmp);
	}
	qsort(anagrams, strsSize, sizeof(Anagrams), anagramsCmp);
	char ***res = (char ***)malloc(sizeof(char **) * strsSize);
	*returnColumnSizes = (int *)malloc(sizeof(int) * strsSize);

	*returnSize = 0;
	for (int i = 1, j = 0; i <= strsSize; ++i)
	{
		if (i == strsSize || strcmp(anagrams[i].str, anagrams[j].str) != 0)
		{
			(*returnColumnSizes)[*returnSize] = i - j;
			res[*returnSize] = (char **)malloc(sizeof(char *) * (*returnColumnSizes)[*returnSize]);
			for (int k = 0; k < i - j; ++k)
				res[*returnSize][k] = strdup(strs[anagrams[j + k].index]);
			++*returnSize;
			j = i;
		}
	}
	return res;
}