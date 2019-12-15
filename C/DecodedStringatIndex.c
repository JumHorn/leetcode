

char *decodeAtIndex(char *S, int K)
{
	long len = 0;
	char *p = S;
	while (len < K)
	{
		if (*p <= '9') //is digits
			len *= *p - '0';
		else
			len++;
		p++;
	}
	--p;
	if (*p > '9') //not digits
	{
		*(p + 1) = '\0';
		return p;
	}
	int k = K % (len / (*p - '0'));
	if (k == 0)
	{
		while (*p <= '9')
			--p;
		*(p + 1) = '\0';
		return p;
	}
	return decodeAtIndex(S, k);
}