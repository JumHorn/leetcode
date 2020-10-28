
int countBinarySubstrings(char* s)
{
	int curContiguousCount = 0, preContiguousCount = 0, res = 0;
	char bin = '\0';
	for (int i = 0; s[i]; ++i)
	{
		if (bin != s[i])
		{
			bin = s[i];
			preContiguousCount = curContiguousCount;
			curContiguousCount = 0;
		}
		if (++curContiguousCount <= preContiguousCount)
			++res;
	}
	return res;
}
