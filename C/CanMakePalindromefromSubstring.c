#include <stdlib.h>
#include <string.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* canMakePaliQueries(char* s, int** queries, int queriesSize, int* queriesColSize, int* returnSize)
{
	bool* res = (bool*)malloc(queriesSize * sizeof(bool));
	*returnSize = queriesSize;
	int len = strlen(s);
	int** dp = (int**)malloc((len + 1) * sizeof(int*));
	for (int i = 0; i <= len; i++)
		dp[i] = (int*)malloc(26 * sizeof(int));
	memset(dp[0], 0, sizeof(int) * 26);
	for (int i = 0; i < len; i++)
	{
		memcpy(dp[i + 1], dp[i], sizeof(int) * 26);
		++dp[i + 1][s[i] - 'a'];
	}

	for (int i = 0; i < queriesSize; i++)
	{
		int map[26];
		for (int j = 0; j < 26; j++)
			map[j] = dp[queries[i][1] + 1][j] - dp[queries[i][0]][j];
		int r = 0;
		for (int j = 0; j < 26; j++)
			r += (map[j] & 1);
		if ((queries[i][1] - queries[i][0]) % 2 == 0)
			r -= 1;
		r /= 2;
		res[i] = (queries[i][2] >= r);
	}
	return res;
}
