#include <stdbool.h>

bool isValid(char *s)
{
	int top = -1;
	char *p = s;
	while (*p)
	{
		if (*p == 'c' && top >= 1 && s[top] == 'b' && s[top - 1] == 'a')
			top -= 2;
		else
			s[++top] = *p;
		++p;
	}
	return top == -1;
}