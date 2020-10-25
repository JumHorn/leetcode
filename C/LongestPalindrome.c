#include <string.h>

int longestPalindrome(char *s)
{
	int count['z' - 'A' + 1] = {0}, res = 0, N = strlen(s);
	for (int i = 0; i < N; ++i)
	{
		if (++count[s[i] - 'A'] == 2)
		{
			count[s[i] - 'A'] = 0;
			res += 2;
		}
	}
	if (N % 2 == 0)
		res += (res == N ? 0 : 1);
	return res + N % 2;
}