
int titleToNumber(char *s)
{
	int res = 0;
	for (int i = 0; s[i]; ++i)
		res = res * 26 + (s[i] - 'A' + 1);
	return res;
}