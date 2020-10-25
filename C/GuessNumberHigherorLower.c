/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int num);

int guessNumber(int n)
{
	int lo = 1, hi = n;
	while (lo < hi)
	{
		int mi = (hi - lo) / 2 + lo;
		int g = guess(mi);
		if (g == 0)
			return mi;
		if (g > 0)
			lo = mi + 1;
		else
			hi = mi - 1;
	}
	return lo;
}
