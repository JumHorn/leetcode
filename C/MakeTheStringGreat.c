#include <ctype.h>

char* makeGood(char* s)
{
	int top = -1;
	for (int i = 0; s[i]; ++i)
	{
		if (top != -1 && s[top] != s[i] && tolower(s[top]) == tolower(s[i]))
			--top;
		else
			s[++top] = s[i];
	}
	s[top + 1] = '\0';
	return s;
}
