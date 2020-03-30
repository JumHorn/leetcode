#include <string.h>

/*
greedy solution to only expand the last * we met
*/

bool isMatch(char *s, char *p)
{
	int i = 0, j = 0, m = 0, n = 0;	 //n is the last * position
	while (s[i])
	{
		if (p[j] == '?' || p[j] == s[i])
		{
			i++;
			j++;
		}
		else if (p[j] == '*')
		{
			n = j++;
			m = i;
		}
		else if (p[n] == '*')
		{
			i = ++m;
			j = n + 1;
		}
		else
			return false;
	}
	while (p[j] && p[j] == '*')
		j++;
	return !p[j];
}
