
void dfs(char *data, int dataSize, int index, int parenthesis, int *size, char (*res)[20])
{
	if (index >= dataSize)
	{
		if (parenthesis == 0)
		{
			strcpy(res[*size], data);
			++*size;
		}
		return;
	}
	if (parenthesis > 0)
	{
		data[index] = ')';
		dfs(data, dataSize, index + 1, parenthesis - 1, size, res);
	}
	data[index] = '(';
	dfs(data, dataSize, index + 1, parenthesis + 1, size, res);
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **generateParenthesis(int n, int *returnSize)
{
	static char staticRes[10000][20];
	*returnSize = 0;
	char data[2 * n + 1];
	data[2 * n] = '\0';
	dfs(data, 2 * n, 0, 0, returnSize, staticRes);

	char **res = (char **)malloc(sizeof(char *) * (*returnSize));
	for (int i = 0; i < *returnSize; ++i)
	{
		res[i] = (char *)malloc(sizeof(char) * (2 * n + 1));
		strcpy(res[i], staticRes[i]);
	}
	return res;
}