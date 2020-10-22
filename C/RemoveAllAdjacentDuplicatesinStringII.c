#include <string.h>

char *removeDuplicates(char *s, int k)
{
	int top = 0, N = strlen(s);
	int count[N];
	count[0] = 0;
	for (int i = 0; i < N; ++i, ++top)
	{
		s[top] = s[i];
		count[top] = (top > 0 && s[top - 1] == s[i] ? count[top - 1] + 1 : 1);
		if (count[top] == k)
			top -= k;
	}
	s[top] = '\0';
	return s;
}