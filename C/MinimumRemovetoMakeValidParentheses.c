
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
	while (top != -1)
	{
		s[stack[top]] = '*';
		--top;
	}
	int j = 0;
	for (int i = 0; s[i]; ++i)
	{
		if (s[i] != '*')
			s[j++] = s[i];
	}
	s[j] = '\0';
	return s;
}