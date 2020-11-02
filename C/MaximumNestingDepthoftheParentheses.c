
#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxDepth(char* s)
{
	int res = 0, parethese = 0;
	for (int i = 0; s[i]; ++i)
	{
		if (s[i] == '(')
			++parethese;
		else if (s[i] == ')')
			--parethese;
		res = max(res, parethese);
	}
	return res;
}
