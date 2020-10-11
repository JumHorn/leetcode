#include <string>
using namespace std;

class Solution
{
public:
	bool checkPalindromeFormation(string a, string b)
	{
		if (isPalindrome(a, 0, a.length() - 1) || isPalindrome(b, 0, b.length() - 1))
			return true;
		int i = 0, j = a.length() - 1;
		while (i < j)
		{
			if (a[i] != b[j])
				break;
			++i;
			--j;
		}
		if (isPalindrome(b, i, j) || isPalindrome(a, i, j))
			return true;
		i = 0, j = a.length() - 1;
		while (i < j)
		{
			if (b[i] != a[j])
				break;
			++i;
			--j;
		}
		return isPalindrome(a, i, j) || isPalindrome(b, i, j);
	}

	bool isPalindrome(const string &a, int i, int j)
	{
		while (i < j)
		{
			if (a[i] != a[j])
				return false;
			++i;
			--j;
		}
		return true;
	}
};