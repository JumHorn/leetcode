
#define max(a, b) (((a) > (b)) ? (a) : (b))
#define min(a, b) (((a) < (b)) ? (a) : (b))

int maxRepOpt1(char* text)
{
	int count[26] = {0}, res = 0;
	for (int i = 0; text[i]; ++i)
		++count[text[i] - 'a'];
	for (char c = 'a'; c <= 'z'; ++c)
	{
		int i = 0, j = 0, gap = 0;
		for (; text[j]; ++j)
		{
			gap += (text[j] != c ? 1 : 0);
			if (gap > 1)
				gap -= (text[i++] != c ? 1 : 0);
		}
		res = max(res, min(j - i, count[c - 'a']));
	}
	return res;
}
