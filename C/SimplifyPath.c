

char *simplifyPath(char *path)
{
	char *p = path;
	char *top = path;
	while (*p)
	{
		if (*p == '/')
		{
			++p;
			continue;
		}
		if (*p == '.')
		{
			++p;
			if (!*p)
				break;
			if (*p == '.')
			{
				++p;
				if (*p == '/' || *p == '\0')
				{
					if (*p)
						++p;
					if (top != path)
						--top;
					while (*top != '/')
						--top;
				}
				else
				{
					p -= 2;
					while (*p && *p != '/')
						*++top = *p++;
					if (*p)
						*++top = *p++;
				}
			}
			else if (*p == '/')
				++p;
			else
			{
				--p;
				while (*p && *p != '/')
					*++top = *p++;
				if (*p)
					*++top = *p++;
			}
		}
		else
		{
			while (*p && *p != '/')
				*++top = *p++;
			if (*p)
				*++top = *p++;
		}
	}
	if (top != path && *top == '/')
		*top = '\0';
	else
		*++top = '\0';
	return path;
}