
char *minRemoveToMakeValid(char *s)
{
	int stack[10000], top = -1;
	for (int i = 0; s[i]; ++i)
	{
		if (s[i] == '(')
			stack[++top] = i;
		else if (s[i] == ')')
			top == -1 ? s[i] = '*' : --top;
	}
	for (; top != -1; --top)
		s[stack[top]] = '*';
	int j = 0;
	for (int i = 0; s[i]; ++i)
	{
		if (s[i] != '*')
			s[j++] = s[i];
	}
	s[j] = '\0';
	return s;
}