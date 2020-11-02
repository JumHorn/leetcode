
char choose(char pre, char after)
{
	for (char c = 'a'; c <= 'z'; ++c)
	{
		if (c != pre && c != after)
			return c;
	}
	return ' ';
}

char* modifyString(char* s)
{
	char pre = '\0';
	for (int i = 0; s[i]; ++i)
	{
		if (s[i] == '?')
		{
			char c = choose(pre, s[i + 1]);
			s[i] = c;
		}
		pre = s[i];
	}
	return s;
}
