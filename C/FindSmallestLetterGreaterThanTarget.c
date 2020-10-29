
char nextGreatestLetter(char *letters, int lettersSize, char target)
{
	int lo = 0, hi = lettersSize - 1;
	if (letters[hi] <= target)
		return letters[0];
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		if (letters[mi] <= target)
			lo = mi + 1;
		else
			hi = mi;
	}
	return letters[lo];
}