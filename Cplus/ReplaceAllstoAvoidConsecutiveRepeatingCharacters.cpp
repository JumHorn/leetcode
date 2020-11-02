#include <string>
using namespace std;

class Solution
{
public:
	string modifyString(string s)
	{
		char pre = '\0';
		int N = s.length();
		for (int i = 0; i < N; ++i)
		{
			if (s[i] == '?')
			{
				char c = choose(pre, i + 1 < N ? s[i + 1] : '\0');
				s[i] = c;
			}
			pre = s[i];
		}
		return s;
	}

	char choose(char pre, char after)
	{
		for (char c = 'a'; c <= 'z'; ++c)
		{
			if (c != pre && c != after)
				return c;
		}
		return ' ';
	}
};