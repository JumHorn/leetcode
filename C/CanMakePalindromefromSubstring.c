#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* canMakePaliQueries(char* s, int** queries, int queriesSize, int* queriesColSize, int* returnSize)
{
	bool* res = (bool*)malloc(queriesSize * sizeof(bool));
	*returnSize = queriesSize;
	for (int i = 0; i < queriesSize; i++)
	{
		char map[26] = {0};
		for (int j = queries[i][0]; j <= queries[i][1]; j++)
			++map[s[j] - 'a'];
		int r = 0;
		for (int j = 0; j < 26; j++)
			r += (map[j] & 1);
		if ((queries[i][1] - queries[i][0]) % 2 == 0)
			r -= 1;
		r /= 2;
		if (r <= queries[i][2])
			res[i] = true;
		else
			res[i] = false;
	}

	return res;
}

