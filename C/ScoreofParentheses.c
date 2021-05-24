
int scoreOfParentheses(char *S)
{
	int base = 1, res = 0;
	for (char *top = S; *S; ++S)
	{
		if (*S == '(')
		{
			base <<= 1;
			top = S;
		}
		else
		{
			base >>= 1;
			if (S - top == 1)
				res += base;
		}
	}
	return res;
}