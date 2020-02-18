

bool isValid(char *S)
{
	int top = -1;
	char *p = S;
	while (*p)
	{
		if (*p != 'c')
			S[++top] = *p;
		else
		{
			if (top < 1)
				S[++top] = *p;
			else
			{
				if (S[top] == 'b' && S[top - 1] == 'a')
					top -= 2;
				else
					S[++top] = *p;
			}
		}
		p++;
	}
	return top == -1;
}