#include <stdlib.h>
#include <string.h>

static int hash[26];

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return hash[*(char *)lhs - 'a'] - hash[*(char *)rhs - 'a'];
}

char *customSortString(char *S, char *T)
{
	memset(hash, 1 << 6, sizeof(hash));
	for (int i = 0; S[i]; ++i)
		hash[S[i] - 'a'] = i;
	qsort(T, strlen(T), sizeof(char), cmp);
	return T;
}