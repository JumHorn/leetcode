
int minFlips(char* target)
{
	int flip = 0, res = 0;
	for (int i = 0; target[i]; ++i)
	{
		if (target[i] != flip % 2 + '0')
		{
			++flip;
			++res;
		}
	}
	return res;
}
