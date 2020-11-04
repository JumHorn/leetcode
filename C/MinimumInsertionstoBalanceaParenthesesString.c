
int minInsertions(char* s)
{
	int right = 0, res = 0;
	for (int i = 0; s[i]; ++i)
	{
		if (s[i] == '(')
		{
			if (right % 2 > 0)
			{
				--right;
				++res;
			}
			right += 2;
		}
		else
		{
			--right;
			if (right < 0)
			{
				right += 2;
				++res;
			}
		}
	}
	return res + right;
}
