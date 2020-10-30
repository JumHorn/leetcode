
char *removeOuterParentheses(char *S)
{
	char *p = S;
	int count = 0;
	for (int i; S[i]; ++i)
	{
		if (S[i] == '(')
		{
			if (count++ != 0)
				*p++ = S[i];
		}
		else if (S[i] == ')')
		{
			if (--count != 0)
				*p++ = S[i];
		}
	}
	*p = '\0';
	return S;
}