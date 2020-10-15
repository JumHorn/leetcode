
int minAddToMakeValid(char *S)
{
	int left = 0, res = 0;
	while (*S)
	{
		if (*S++ == '(')
			++left;
		else
			left > 0 ? --left : ++res;
	}
	return res + left;
}