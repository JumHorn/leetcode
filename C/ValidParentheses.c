#include <stdbool.h>

bool isValid(char *s)
{
	int map[128];
	map[')'] = '(';
	map['}'] = '{';
	map[']'] = '[';
	int top = -1; //view s as in-place stack
	for (int i = 0; s[i]; ++i)
	{
		if (s[i] == ')' || s[i] == '}' || s[i] == ']')
		{
			if (top == -1 || s[top] != map[s[i]])
				return false;
			--top;
		}
		else
			s[++top] = s[i];
	}
	return top == -1;
}