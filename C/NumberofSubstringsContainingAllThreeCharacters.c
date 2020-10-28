
int numberOfSubstrings(char* s)
{
	int hash[3] = {0, 0, 0}, res = 0;
	for (int i = 0, j = 0; s[i]; ++i)
	{
		++hash[s[i] - 'a'];
		while (hash[0] && hash[1] && hash[2])
			--hash[s[j++] - 'a'];
		res += j;
	}
	return res;
}
