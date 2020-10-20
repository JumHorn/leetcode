#include <string.h>

/*
using kmp preprocess
create next array using dp
*/

char *longestPrefix(char *s)
{
	int n = strlen(s);
	int next[n];
	memset(next, 0, sizeof(next));
	for (int i = 1; i < n; ++i)
	{
		int j = next[i - 1];
		while (j > 0 && s[j] != s[i])
			j = next[j - 1];
		if (s[j] == s[i])
			j++;
		next[i] = j;
	}
	s[next[n - 1]] = '\0';
	return s;
}