#include <cmath>
using namespace std;

/*
build palindrome first
*/

class Solution
{
public:
	int largestPalindrome(int n)
	{
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

private:
	static const int MOD = 1337;
};