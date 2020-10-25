#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

class Solution
{
public:
	string reverseVowels(string s)
	{
		int i = 0, j = s.length() - 1;
		while (i < j)
		{
			if (!isVowel(s[i]))
				++i;
			else if (!isVowel(s[j]))
				--j;
			else
			{
				swap(s[i], s[j]);
				++i;
				--j;
			}
		}
		return s;
	}

	bool isVowel(char c)
	{
		c = tolower(c);
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
	}
};