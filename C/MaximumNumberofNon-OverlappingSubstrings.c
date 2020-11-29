#include <stdlib.h>
#include <string.h>

#define max(a, b) (((a) > (b)) ? (a) : (b))

int checkStr(const char *s, int start, int *left, int *right)
{
	int maxright = right[s[start] - 'a'];
	for (int i = start; i < maxright; ++i)
	{
		if (left[s[i] - 'a'] < start)
			return -1;
		maxright = max(maxright, right[s[i] - 'a']);
	}
	return maxright;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char **maxNumOfSubstrings(char *s, int *returnSize)
{
	int left[26] = {0}, right[26] = {0};
	int N = strlen(s);
	for (int i = 0; i < N; ++i)
		right[s[i] - 'a'] = i;
	for (int i = N - 1; i >= 0; --i)
		left[s[i] - 'a'] = i;

	char **res = (char **)malloc(sizeof(char *) * 1000);
	*returnSize = 1;
	int last_right = N;
	for (int i = 0; i < N; ++i)
	{
		if (i == left[s[i] - 'a'])
		{
			int rightmost = checkStr(s, i, left, right);
			if (rightmost != -1)
			{
				if (i > last_right)
					++*returnSize;
				last_right = rightmost;
				res[*returnSize - 1] = strndup(&s[i], rightmost - i + 1);
			}
		}
	}
	return res;
}