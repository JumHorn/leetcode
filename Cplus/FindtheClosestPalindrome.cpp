#include <climits>
#include <cmath>
#include <string>
using namespace std;

class Solution
{
public:
	string nearestPalindromic(string n)
	{
		long num = stoll(n);
		int N = n.length();
		n[(N + 1) / 2] = '\0';
		long half = stoll(n.substr(0, (N + 1) / 2));
		long res0 = makePalindrome(half, N % 2);
		long abs0 = abs(num - res0);
		if (abs0 == 0)
			abs0 = LONG_MAX;

		long res1;
		if (half != pow(10, (N + 1) / 2) - 1)
			res1 = makePalindrome(half + 1, N % 2);
		else
			res1 = pow(10, N) + 1;
		long abs1 = abs(num - res1);

		long res2;
		if (half != pow(10, (N + 1) / 2 - 1))
			res2 = makePalindrome(half - 1, N % 2);
		else
			res2 = pow(10, N - 1) - 1;
		long abs2 = abs(num - res2);

		if (abs2 <= abs0 && abs2 <= abs1)
			return to_string(res2);
		if (abs0 <= abs1 && abs0 < abs2)
			return to_string(res0);
		return to_string(res1);
	}

	long makePalindrome(long half, int even)
	{
		long left = half, right = 0;
		if (even != 0)
			half /= 10;
		for (; half > 0; half /= 10)
		{
			left *= 10;
			right = right * 10 + half % 10;
		}
		return left + right;
	}
};