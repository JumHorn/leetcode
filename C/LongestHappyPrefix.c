#include <string.h>

/*
using kmp preprocess
create next array using dp
*/

char *longestPrefix(char *s)
{
	int N = strlen(s);
	int next[N];
	memset(next, 0, sizeof(next));
	for (int i = 1; i < N; ++i)
	{
		int j = next[i - 1];
		while (j > 0 && s[j] != s[i])
			j = next[j - 1];
		if (s[j] == s[i])
			++j;
		next[i] = j;
	}
	s[next[N - 1]] = '\0';
	return s;
}