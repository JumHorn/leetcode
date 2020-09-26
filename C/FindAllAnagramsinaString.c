#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool equalArray(int* shash, int* phash)
{
	for (int i = 0; i < 26; ++i)
	{
		if (shash[i] != phash[i])
			return false;
	}
	return true;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(char* s, char* p, int* returnSize)
{
	int shash[26] = {0}, phash[26] = {0};
	int slen = strlen(s), plen = strlen(p);
	*returnSize = 0;
	if (plen > slen)
		return NULL;
	for (int i = 0; i < plen; ++i)
		++phash[p[i] - 'a'];
	for (int i = 0; i < plen; ++i)
		++shash[s[i] - 'a'];
	int* res = (int*)malloc(sizeof(int) * 20101);
	if (equalArray(shash, phash))
		res[(*returnSize)++] = 0;
	for (int i = 0; i < slen - plen; ++i)
	{
		--shash[s[i] - 'a'];
		++shash[s[i + plen] - 'a'];
		if (equalArray(shash, phash))
			res[(*returnSize)++] = i + 1;
	}
	return res;
}
