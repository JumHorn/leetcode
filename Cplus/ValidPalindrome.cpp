#include <cctype>
#include <string>
using namespace std;

class Solution
{
public:
	bool isPalindrome(string s)
	{
		int i = 0, j = s.length() - 1;
		while (i < j)
		{
			if (!isalnum(s[i]))
				++i;
			else if (!isalnum(s[j]))
				--j;
			else
			{
				if (toupper(s[i]) != toupper(s[j]))
					return false;
				++i;
				--j;
			}
		}
		return true;
	}
};