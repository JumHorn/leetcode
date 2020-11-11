#include <stdlib.h>
#include <string.h>

//integer cmp function
int cmp(const void *lhs, const void *rhs)
{
	if (*(int *)lhs == *(int *)rhs)
		return 0;
	return *(int *)lhs < *(int *)rhs ? -1 : 1;
}

char *frequencySort(char *s)
{
	int hash[256][2]; //{count,character}
	for (int i = 0; i < 256; ++i)
	{
		hash[i][0] = 0;
		hash[i][1] = i;
	}
	for (int i = 0; s[i]; ++i)
		++hash[(int)s[i]][0];
	qsort(hash, 256, sizeof(hash[0]), cmp);
	int size = 0;
	for (int i = 0; i < 256; ++i)
	{
		memset(s + size, hash[i][1], sizeof(char) * hash[i][0]);
		size += hash[i][0];
	}
	return s;
}