#include <stdbool.h>
#include <stdlib.h>

bool isMath(char* query, char* pattern)
{
	int i = 0;
	for (int j = 0; query[j]; ++j)
	{
		if (query[j] == pattern[i])
			++i;
		else if (query[j] < 'a' || query[j] > 'z')
			return false;
	}
	return !pattern[i];
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* camelMatch(char** queries, int queriesSize, char* pattern, int* returnSize)
{
	*returnSize = queriesSize;
	bool* res = (bool*)malloc(sizeof(bool) * (*returnSize));
	for (int i = 0; i < queriesSize; ++i)
		res[i] = isMath(queries[i], pattern);
	return res;
}
