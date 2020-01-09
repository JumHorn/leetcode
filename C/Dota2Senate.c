
char *predictPartyVictory(char *senate)
{
	int skip = 0;
	while (true)
	{
		int r = 0, d = 0;
		char *p = senate;
		while (*p)
		{
			if (*p == 'R')
			{
				if (skip > 0)
				{
					*p = '.';
					--skip;
				}
				else
				{
					++r;
					--skip;
				}
			}
			else if (*p == 'D')
			{
				if (skip < 0)
				{
					*p = '.';
					++skip;
				}
				else
				{
					++d;
					++skip;
				}
			}
			++p;
		}
		if (d + skip <= 0)
			return "Radiant";
		if (r - skip <= 0)
			return "Dire";
	}
	return "";
}

int main()
{
	char str[] = "DRRDRD";
	predictPartyVictory(str);
	return 0;
}