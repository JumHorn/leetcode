#include <stdbool.h>

bool isSubsequence(char* s, char* t)
{
	int i = 0, j = 0;
	for (; s[i] && t[j]; ++j)
	{
		if (s[i] == t[j])
			++i;
	}
	return !s[i];
}
