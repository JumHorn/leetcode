
int minSteps(char* s, char* t)
{
	int hash[26] = {0};
	for (int i = 0; s[i]; ++i)
	{
		++hash[s[i] - 'a'];
		--hash[t[i] - 'a'];
	}
	int res = 0;
	for (int i = 0; i < 26; ++i)
	{
		if (hash[i] > 0)
			res += hash[i];
	}
	return res;
}
