#include <math.h>

int largestPalindrome(int n)
{
	static const int MOD = 1337;
	for (long halfval = pow(10, n) - 1; halfval > 0; halfval--)
	{
		long left = halfval, right = 0, palindrome;
		for (long i = halfval; i > 0; i /= 10)
		{
			right = right * 10 + i % 10;
			left *= 10;
		}
		palindrome = left + right;
		for (long i = pow(10, n) - 1; i * i >= palindrome; --i)
		{
			if (palindrome % i == 0)
				return palindrome % MOD;
		}
	}
	return 9;
}