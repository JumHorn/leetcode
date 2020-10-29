#include <stdbool.h>
#include <string.h>

void backspace(char* s)
{
	int top = -1;
	for (int i = 0; s[i]; ++i)
	{
		if (s[i] != '#')
			s[++top] = s[i];
		else if (top != -1)
			--top;
	}
	s[top + 1] = '\0';
}

bool backspaceCompare(char* S, char* T)
{
	backspace(S);
	backspace(T);
	return strcmp(S, T) == 0;
}
