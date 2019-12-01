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
	int** dp = (int**)malloc(len * sizeof(int*));
	for (int i = 0; i < len; i++)
	{
		dp[i] = (int*)malloc(len * sizeof(int));
		dp[i][i] = 0;
		if (i != 0)
			dp[i][i - 1] = 0;
	}
	for (int j = 1; j < len; j++)
		for (int i = j - 1; i >= 0; i--)
		{
			if (s[i] == s[j])
				dp[i][j] = dp[i + 1][j - 1];
			else
				dp[i][j] = dp[i + 1][j - 1] + 1;
		}

	for (int i = 0; i < queriesSize; i++)
	{
		if (queries[i][2] >= dp[queries[i][0]][queries[i][1]])
			res[i] = true;
		else
			res[i] = false;
	}

	return res;
}

