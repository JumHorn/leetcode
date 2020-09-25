
char* removeKdigits(char* num, int k)
{
	int top = -1;  //view num as stack
	for (int i = 0; num[i]; ++i)
	{
		while (k > 0 && top != -1 && num[top] > num[i])
		{
			--top;
			--k;
		}
		num[++top] = num[i];
	}
	while (--k >= 0)
		--top;
	num[top + 1] = '\0';
	while (*num == '0')
		++num;
	return *num ? num : "0";
}
