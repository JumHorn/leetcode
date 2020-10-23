
int minimumSwap(char* s1, char* s2)
{
	int x1 = 0, y1 = 0;
	for (int i = 0; s1[i]; ++i)
	{
		if (s1[i] != s2[i])
			s1[i] == 'x' ? ++x1 : ++y1;
	}
	if ((x1 + y1) % 2 != 0)
		return -1;
	return (x1 + y1) / 2 + x1 % 2;
}
