
int numSplits(char* s)
{
	int left[26] = {0}, right[26] = {0};
	for (int i = 0; s[i]; ++i)
		++right[s[i] - 'a'];
	int res = 0, leftcount = 0, rightcount = 0;
	for (int i = 0; i < 26; ++i)
		rightcount += right[i] > 0 ? 1 : 0;
	for (int i = 0; s[i]; ++i)
	{
		if (--right[s[i] - 'a'] == 0)
			--rightcount;
		if (left[s[i] - 'a'] == 0)
			++leftcount;
		++left[s[i] - 'a'];
		if (rightcount == leftcount)
			++res;
	}
	return res;
}
