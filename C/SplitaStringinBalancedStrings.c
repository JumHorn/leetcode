
int balancedStringSplit(char *s)
{
	int res = 0, count = 0;
	for (; *s; ++s)
	{
		*s == 'L' ? ++count : --count;
		if (count == 0)
			++res;
	}
	return res;
}