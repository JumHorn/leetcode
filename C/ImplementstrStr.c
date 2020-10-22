#include <string.h>

int strStr(char* haystack, char* needle)
{
	if (!*needle)
		return 0;
	int M = strlen(haystack), N = strlen(needle);
	int next[N];
	next[0] = 0;
	for (int i = 1, j = 0; i < N; ++i)
	{
		while (j > 0 && needle[i] != needle[j])
			j = next[j - 1];
		if (needle[i] == needle[j])
			++j;
		next[i] = j;
	}
	int i = 0, j = 0;
	while (i < M && j < N)
	{
		if (haystack[i] == needle[j])
		{
			++j;
			++i;
		}
		else
			j > 0 ? j = next[j - 1] : ++i;
	}
	return j == N ? i - j : -1;
}
