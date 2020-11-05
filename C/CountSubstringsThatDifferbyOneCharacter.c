
int countSubstrings(char* s, char* t)
{
	int res = 0;
	for (int i = 0; s[i]; ++i)
	{
		for (int j = 0; t[j]; ++j)
		{
			int diff = 0;
			for (int k = 0; s[i + k] && t[j + k] && diff < 2; ++k)
			{
				if (s[i + k] != t[j + k])
					++diff;
				if (diff == 1)
					++res;
			}
		}
	}
	return res;
}
