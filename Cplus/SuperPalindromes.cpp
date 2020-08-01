#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution
{
public:
	int superpalindromesInRange(string L, string R)
	{
		long long l = stoll(L), r = stoll(R);
		int res = 0, magic = 1e5;
		for (long long i = 1; i < magic; i++)
		{
			string str = to_string(i), reverse_str = str;
			reverse(reverse_str.begin(), reverse_str.end());
			str += reverse_str;
			long long val = stoll(str);
			val *= val;
			if (val > r)
				break;
			if (val >= l && isPalindrome(val))
				++res;
		}
		for (long long i = 1; i < magic; i++)
		{
			string str = to_string(i), reverse_str = str.substr(0, str.length() - 1);
			reverse(reverse_str.begin(), reverse_str.end());
			str += reverse_str;
			long long val = stoll(str);
			val *= val;
			if (val > r)
				break;
			if (val >= l && isPalindrome(val))
				++res;
		}
		return res;
	}

	bool isPalindrome(long long x)
	{
		string str = to_string(x);
		int i = 0, j = str.length() - 1;
		while (i < j)
		{
			if (str[i++] != str[j--])
				return false;
		}
		return true;
	}
};