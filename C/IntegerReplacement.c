/*
to examine the last two digits to figure out whether incrementing or decrementing will give more 1's.
if a number ends with 01, then certainly decrementing is the way to go.
Otherwise, if it ends with 11, then certainly incrementing is at least as good as decrementing
(*011 -> *010 / *100) or even better (if there are three or more 1's).
*/

int integerReplacement(int n)
{
	int res = 0;
	for (unsigned int N = n; N > 1;)
	{
		++res;
		if ((N & 1) == 0)
			N >>= 1;
		else if (N == 3 || ((N >> 1) & 1) == 0)
			--N;
		else
			++N;
	}
	return res;
}