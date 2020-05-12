#include <algorithm>
#include <string>
using namespace std;

/*
For any repeating sequences with len % 3 == 0, we can reduce one replacement by deleting one character.
For any repeating sequences with len % 3 == 1, we can reduce one replacement by deleting two character.
For the remaining sequences, we can reduce every replacement by deleting three character.
*/

class Solution
{
public:
	int strongPasswordChecker(string s)
	{
		int missing = 0, n = s.length();
		missing += anyof(s, '1', '9');
		missing += anyof(s, 'a', 'z');
		missing += anyof(s, 'A', 'Z');
		int change = 0, one = 0 /*mod3==0*/, two = 0 /*mod3==1*/;
		for (int i = 2; i < n;)
		{
			if (s[i] == s[i - 1] && s[i] == s[i - 2])
			{
				int count = 2;
				while (i < n && s[i] == s[i - 1])
				{
					++count;
					++i;
				}
				change += count / 3;
				if (count % 3 == 0)
					++one;
				if (count % 3 == 1)
					++two;
			}
			else
				++i;
		}
		if (n < 6)
			return max(missing, 6 - n);
		if (n <= 20)
			return max(missing, change);
		int deletion = n - 20;
		change -= min(deletion, one);
		change -= min(max(deletion - one, 0) / 2, two);
		change -= max(deletion - one - two * 2, 0) / 3;
		return deletion + max(missing, change);
	}

	int anyof(const string &s, char low, char up)
	{
		for (auto c : s)
		{
			if (c >= low && c <= up)
				return 0;
		}
		return 1;
	}
};