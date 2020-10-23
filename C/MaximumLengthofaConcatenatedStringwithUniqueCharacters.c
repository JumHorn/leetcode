#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int dfs(char **arr, int arrSize, int index, char *str, int strSize)
{
	int mask = 0;
	for (int i = 0; i < strSize; ++i)
	{
		if (mask & (1 << (str[i] - 'a')))
			return 0;
		mask |= 1 << (str[i] - 'a');
	}
	int res = strSize;
	for (int i = index; i < arrSize; ++i)
	{
		int len = strlen(arr[i]);
		memcpy(&str[strSize], arr[i], sizeof(char) * len);
		int val = dfs(arr, arrSize, i + 1, str, strSize + len);
		res = max(res, val);
	}
	return res;
}

int maxLength(char **arr, int arrSize)
{
	char str[1000] = {0};
	return dfs(arr, arrSize, 0, str, 0);
}