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

bool isSubsequence(char *lhs, char *rhs) //lhs is subsequence of rhs
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

char *findLongestWord(char *s, char **d, int dSize)
{
	qsort(d, dSize, sizeof(char *), cmp);
	for (int i = 0; i < dSize; ++i)
	{
		if (isSubsequence(d[i], s))
			return d[i];
	}
	return "";
}