

int balancedStringSplit(char* s)
{
	int res = 0, count = 0;
	while (*s)
	{
		if (*s == 'L')
			count++;
		else
			count--;
		if (count == 0)
			res++;
		++s;
	}
	return res;
}

