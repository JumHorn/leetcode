#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *lhs, const void *rhs)
{
	char *l = *(char **)lhs, *r = *(char **)rhs;
	int llen = strlen(l), rlen = strlen(r);
	if (llen != rlen)
		return rlen - llen;
	return strcmp(l, r);
}

bool isSubsequence(char *lhs, char *rhs)  //lhs is subsequence of rhs
{
	unsigned int i = 0, j = 0;
	while (lhs[i] && rhs[j])
	{
		if (lhs[i] == rhs[j])
			++i;
		++j;
	}
	return !lhs[i];
}

int findLUSlength(char **strs, int strsSize)
{
	qsort(strs, strsSize, sizeof(char *), cmp);
	for (int i = 0; i < strsSize; ++i)
	{
		if (i != strsSize - 1 && strcmp(strs[i], strs[i + 1]) == 0)
			continue;
		if (i != 0 && strcmp(strs[i], strs[i - 1]) == 0)
			continue;
		int j;
		for (j = 0; j < i; ++j)
		{
			if (isSubsequence(strs[i], strs[j]))
				break;
		}
		if (j == i)
			return strlen(strs[i]);
	}
	return -1;
}
