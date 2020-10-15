#include <stdbool.h>
#include <stdlib.h>

bool checkString(char *s, int *count)
{
	int v[26] = {0};
	for (int i = 0; s[i]; ++i)
		++v[s[i] - 'a'];
	for (int i = 0; i < 26; ++i)
	{
		if (v[i] < count[i])
			return false;
	}
	return true;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **wordSubsets(char **A, int ASize, char **B, int BSize, int *returnSize)
{
	int index[ASize], count[26] = {0};
	*returnSize = 0;
	for (int i = 0; i < BSize; ++i)
	{
		int v[26] = {0};
		for (int j = 0; B[i][j]; ++j)
		{
			int index = B[i][j] - 'a';
			if (++v[index] > count[index])
				count[index] = v[index];
		}
	}

	for (int i = 0; i < ASize; ++i)
	{
		if (checkString(A[i], count))
			index[(*returnSize)++] = i;
	}

	char **res = (char **)malloc(sizeof(char *) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
	{
		int len = strlen(A[index[i]]);
		res[i] = (char *)malloc(sizeof(char) * (len + 1));
		strcpy(res[i], A[index[i]]);
	}
	return res;
}