
int scoreOfParentheses(char *S)
{
	int left = 0, base = 1, res = 0;
	for (char *top = S; *S; ++S)
	{
		if (*S == '(')
		{
			base <<= 1;
			++left;
			top = S;
		}
		else
		{
			base >>= 1;
			--left;
			if (S - top == 1)
				res += base;
		}
	}
	return res;
}