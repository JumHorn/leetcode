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

char *shortestPalindrome(char *s)
{
	int N = strlen(s);
	char pattern[2 * N + 2];
	strcpy(pattern, s);
	pattern[N] = '#';
	strcpy(&pattern[N + 1], s);
	reverse(pattern, N + 1, 2 * N);
	int next[2 * N + 1];
	next[0] = 0;
	for (int i = 1, j = 0; i <= 2 * N; ++i)
	{
		while (j > 0 && pattern[i] != pattern[j])
			j = next[j - 1];
		if (pattern[i] == pattern[j])
			++j;
		next[i] = j;
	}
	strncpy(pattern, &pattern[N + 1], N - next[2 * N]);
	strcpy(&pattern[N - next[2 * N]], s);
	return strdup(pattern);
}