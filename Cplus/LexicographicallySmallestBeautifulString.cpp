#include <string>
using namespace std;

/*
It does not contain any substring of length 2 or more which is a palindrome
means s[i] != s[i-1] && s[i] != s[i-2] for i in [2,n)
*/

class Solution
{
public:
	string smallestBeautifulString(string s, int k)
	{
		int N = s.size(), i = N - 1;
		k += 'a';
		for (; i >= 0 && s[i] + 1 == k; --i)
			s[i] = 'a';
		if (i < 0)
			return "";
		++s[i];
		while (i >= 0 && i < N)
		{
			if (s[i] == k)
			{
				if (i == 0)
					return "";
				s[i] = 'a';
				--i;
				++s[i];
			}
			else if ((i >= 1 && s[i] == s[i - 1]) || (i >= 2 && s[i] == s[i - 2]))
				++s[i];
			else
				++i;
		}
		return s;
	}
};