#include <stdlib.h>
#include <string.h>

void reverse(char *arr, int first, int last)
{
	for (; first < last; ++first, --last)
	{
		char tmp = arr[first];
		arr[first] = arr[last];
		arr[last] = tmp;
	}
}

void recursion(char *s, int index, int last_remove_index, char *paretheses, char **res, int *resSize)
{
	for (int count = 0, i = index; s[i]; ++i)
	{
		if (s[i] == paretheses[0])
			++count;
		else if (s[i] == paretheses[1])
			--count;
		if (count >= 0)
			continue;
		for (int j = last_remove_index; j <= i; ++j)
		{
			if (s[j] == paretheses[1] &&
				(j == last_remove_index || s[j - 1] != paretheses[1]))
			{
				char removestr[1000];
				strncpy(removestr, s, j);
				strcpy(&removestr[j], &s[j + 1]);
				recursion(removestr, i, j, paretheses, res, resSize);
			}
		}
		return;
	}
	int N = strlen(s);
	reverse(s, 0, N - 1);
	if (paretheses[0] == '(') // finished left to right
		recursion(s, 0, 0, ")(", res, resSize);
	else // finished right to left
		res[(*resSize)++] = strdup(s);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **removeInvalidParentheses(char *s, int *returnSize)
{
	char **res = (char **)malloc(sizeof(char *) * 1000);
	*returnSize = 0;
	recursion(s, 0, 0, "()", res, returnSize);
	return res;
}