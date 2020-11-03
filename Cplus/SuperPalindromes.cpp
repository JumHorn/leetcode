#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

class Solution
{
public:
	int superpalindromesInRange(string L, string R)
	{
		long l = stoll(L), r = stoll(R);
		int res = 0, magic = 1e5;
		for (long i = 1; i < magic; ++i)
		{
			int len = to_string(i).length();
			long val = i * pow(10, len) + reverse(i);
			val *= val;
			if (val > r)
				break;
			if (val >= l && isPalindrome(val))
				++res;
		}
		for (long i = 1; i < magic; ++i)
		{
			int len = to_string(i).length();
			long val = i * pow(10, len - 1) + reverse(i) % (long)pow(10, len - 1);
			val *= val;
			if (val > r)
				break;
			if (val >= l && isPalindrome(val))
				++res;
		}
		return res;
	}

	long reverse(long x)
	{
		long res = 0;
		while (x != 0)
		{
			res = res * 10 + x % 10;
			x /= 10;
		}
		return res;
	}

	bool isPalindrome(long x)
	{
		return x == reverse(x);
	}
};