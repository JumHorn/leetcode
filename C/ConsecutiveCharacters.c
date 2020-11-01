
#define max(a, b) (((a) > (b)) ? (a) : (b))

int maxPower(char* s)
{
	int res = 1, count = 0;
	char pre = '\0';
	for (int i = 0; s[i]; ++i)
	{
		if (pre == s[i])
		{
			++count;
			res = max(res, count);
		}
		else
		{
			count = 1;
			pre = s[i];
		}
	}
	return res;
}
