#include <string>
using namespace std;

class Solution
{
public:
	bool validPalindrome(string s)
	{
		return isPalindrome(s, 0, s.length() - 1, 1);
	}

	bool isPalindrome(string &s, int first, int last, int d)
	{
		while (first < last && s[first] == s[last])
		{
			++first;
			--last;
		}
		return first >= last ||
			   (d == 1 && isPalindrome(s, first + 1, last, 0)) ||
			   (d == 1 && isPalindrome(s, first, last - 1, 0));
	}
};