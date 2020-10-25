
char findTheDifference(char* s, char* t)
{
	int count[26] = {0};
	for (int i = 0; t[i]; ++i)
		++count[t[i] - 'a'];
	for (int i = 0; s[i]; ++i)
		--count[s[i] - 'a'];
	for (int i = 0; i < 26; ++i)
	{
		if (count[i] != 0)
			return 'a' + i;
	}
	return '\0';
}
