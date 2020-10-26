#include <stdbool.h>
#include <string.h>

/*
kmp next array
*/

bool repeatedSubstringPattern(char *s)
{
	int N = strlen(s);
	int next[N + 1];
	next[0] = 0;
	for (int i = 1, j = 0; i < N; ++i)
	{
		while (j > 0 && s[i] != s[j])
			j = next[j - 1];
		if (s[i] == s[j])
			++j;
		next[i] = j;
	}
	return next[N - 1] && next[N - 1] % (N - next[N - 1]) == 0;
}