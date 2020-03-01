

char *minRemoveToMakeValid(char *s)
{
	int count = 0, top = -1;
	char *p = s;
	while (*p)
	{
		if (*p == ')')
		{
			if (count > 0)
			{
				count--;
				s[++top] = *p;
			}
		}
		else
		{
			if (*p == '(')
				count++;
			s[++top] = *p;
		}
		++p;
	}
	s[top + 1] = '\0';
	if (count > 0)
	{
		char *tmp = &s[top];
		while (count > 0)
		{
			if (*tmp == '(')
				count--;
			tmp--;
		}
		p = ++tmp;
		while (++tmp != s + top + 1)
			if (*tmp != '(')
				*p++ = *tmp;
		*p = '\0';
	}
	return s;
}