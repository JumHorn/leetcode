
char *removeDuplicates(char *S)
{
	int top = -1;
	for (int i = 0; S[i]; ++i)
	{
		if (top == -1 || S[top] != S[i])
			S[++top] = S[i];
		else
			--top;
	}
	S[top + 1] = '\0';
	return S;
}