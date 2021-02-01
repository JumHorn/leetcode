#include <string>
using namespace std;

class Solution
{
public:
	string breakPalindrome(string palindrome)
	{
		int i = 0, j = palindrome.length() - 1;
		for (; i < j; ++i, --j)
		{
			if (palindrome[i] != 'a')
			{
				palindrome[i] = 'a';
				return palindrome;
			}
		}
		if (palindrome.size() > 1)
		{
			palindrome.back() = 'b';
			return palindrome;
		}
		return "";
	}
};
