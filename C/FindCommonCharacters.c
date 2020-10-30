#include <stdlib.h>
#include <string.h>

#define min(a, b) (((a) < (b)) ? (a) : (b))

void charCount(char *s, int *hash)
{
	for (int i = 0; s[i]; ++i)
		++hash[s[i] - 'a'];
}

void minArr(int *lhs, int *rhs, int size)
{
	for (int i = 0; i < size; ++i)
		lhs[i] = min(lhs[i], rhs[i]);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **commonChars(char **A, int ASize, int *returnSize)
{
	int hash[26] = {0};
	charCount(A[0], hash);
	for (int i = 1; i < ASize; ++i)
	{
		int map[26] = {0};
		charCount(A[i], map);
		minArr(hash, map, 26);
	}
	*returnSize = 0;
	for (int i = 0; i < 26; ++i)
		*returnSize += hash[i];
	char **res = (char **)malloc(sizeof(char *) * (*returnSize));
	for (int i = 0, j = 0; i < 26; ++i)
	{
		while (--hash[i] >= 0)
		{
			res[j] = strdup("a");
			res[j++][0] += i;
		}
	}
	return res;
}