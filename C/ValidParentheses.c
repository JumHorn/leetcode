#include <stdbool.h>

bool isValid(char* s)
{
	int map[128];
	map[')'] = '(';
	map['}'] = '{';
	map[']'] = '[';
	int i = -1;
	for (int j = 0; s[j]; ++j)
	{
		if (s[j] == ')' || s[j] == '}' || s[j] == ']')
		{
			if (i == -1 || s[i] != map[s[j]])
				return false;
			--i;
		}
		else
			s[++i] = s[j];
	}
	return i == -1;
}
