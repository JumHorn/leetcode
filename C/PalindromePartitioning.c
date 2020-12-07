#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

//malloc result
char ***mallocRes(char (*data)[1001][101], int dataSize, int *dataColSize, int *returnSize, int **returnColumnSizes)
{
	*returnSize = dataSize;
	*returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
	memcpy(*returnColumnSizes, dataColSize, sizeof(int) * (*returnSize));
	char ***res = (char ***)malloc(sizeof(char **) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
	{
		res[i] = (char **)malloc(sizeof(char *) * (*returnColumnSizes)[i]);
		for (int j = 0; j < (*returnColumnSizes)[i]; ++j)
			res[i][j] = strdup(data[i][j]);
	}
	return res;
}

void addOneResult(char (*staticRes)[1001][101], int *resSize, int *colSize, char (*instance)[101], int instanceSize)
{
	for (int i = 0; i < instanceSize; ++i)
		strcpy(staticRes[*resSize][i], instance[i]);
	colSize[(*resSize)++] = instanceSize;
}

void dfs(char *s, int len, int index, bool (*dp)[len], char (*instance)[101], int instanceSize, char (*staticRes)[1001][101], int *resSize, int *colSize)
{
	if (index >= len)
		addOneResult(staticRes, resSize, colSize, instance, instanceSize);
	for (int i = index; i < len; ++i)
	{
		if (!dp[index][i])
			continue;
		strncpy(instance[instanceSize], &s[index], i - index + 1); //don't auto add '\0' to the result
		instance[instanceSize][i - index + 1] = '\0';
		dfs(s, len, i + 1, dp, instance, instanceSize + 1, staticRes, resSize, colSize);
	}
}

/**
 * Return an array of arrays of resSize *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char ***partition(char *s, int *returnSize, int **returnColumnSizes)
{
	static char staticRes[10001][1001][101], instance[1001][101];
	static int staticResColSize[10001];
	memset(staticResColSize, 0, sizeof(staticResColSize));
	*returnSize = 0;

	int N = strlen(s);
	if (N == 0)
		return NULL;
	bool dp[N][N];
	for (int i = N - 1; i >= 0; --i)
	{
		for (int j = i; j < N; ++j)
			dp[i][j] = (i == j || (s[i] == s[j] && (i + 1 == j || dp[i + 1][j - 1])));
	}
	dfs(s, N, 0, dp, instance, 0, staticRes, returnSize, staticResColSize);
	return mallocRes(staticRes, *returnSize, staticResColSize, returnSize, returnColumnSizes);
}