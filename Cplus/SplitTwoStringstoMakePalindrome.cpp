#include <string>
using namespace std;

class Solution
{
public:
	bool checkPalindromeFormation(string a, string b)
	{
		return check(a, b) || check(b, a);
	}

	bool check(string &a, string &b)
	{
		int i = 0, j = (int)a.length() - 1;
		for (; i < j; ++i, --j)
		{
			if (a[i] != b[j])
				break;
		}
		return isPalindrome(b, i, j) || isPalindrome(a, i, j);
	}

	bool isPalindrome(const string &s, int first, int last)
	{
		for (; first < last; ++first, --last)
		{
			if (s[first] != s[last])
				return false;
		}
		return true;
	}
};