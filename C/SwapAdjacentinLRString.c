

bool canTransform(char *start, char *end)
{
	if (!*start && !*end)
		return true;
	if (!*start || !*end)
		return false;
	if (*start == *end)
		return canTransform(++start, ++end);
	if (*start != 'X' && *end != 'X')
		return false;
	if (*end == 'X')
	{
		if (*start == 'L')
			return false;
		char *p = start + 1;
		while (*p)
		{
			if (*p == 'L')
				return false;
			if (*p == 'X')
				break;
			p++;
		}
		if (!*p)
			return false;
		*p = 'R';
		return canTransform(++start, ++end);
	}
	if (*end == 'L')
	{
		if (*start == 'R')
			return false;
		char *p = start;
		while (*p)
		{
			if (*p == 'R')
				return false;
			if (*p == 'L')
				break;
			++p;
		}
		if (!*p)
			return false;
		*p = 'X';
		return canTransform(++start, ++end);
	}
	return false;
}