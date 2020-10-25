#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

//cmp function don't consider overflow
int cmp(const void *lhs, const void *rhs)
{
	return strcmp((char *)lhs, (char *)rhs);
}

int maxFreq(char *s, int maxLetters, int minSize, int maxSize)
{
	int hash[26] = {0}, count = 0, strsSize = 0;
	char strs[100000][minSize + 1];
	memset(strs, 0, sizeof(strs));
	for (int i = 0; i < minSize; ++i)
	{
		if (hash[s[i] - 'a']++ == 0)
			++count;
	}
	if (count <= maxLetters)
		strncpy(strs[strsSize++], &s[0], minSize);
	for (int i = minSize; s[i]; ++i)
	{
		if (--hash[s[i - minSize] - 'a'] == 0)
			--count;
		if (hash[s[i] - 'a']++ == 0)
			++count;
		if (count <= maxLetters)
			strncpy(strs[strsSize++], &s[i - minSize + 1], minSize);
	}
	qsort(strs, strsSize, sizeof(strs[0]), cmp);
	int res = 0;
	for (int i = 1, j = 0; i <= strsSize; ++i)
	{
		if (i == strsSize || strcmp(strs[i], strs[j]) != 0)
		{
			res = max(res, i - j);
			j = i;
		}
	}
	return res;
}