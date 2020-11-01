#include <string>
using namespace std;

class Solution
{
public:
	string freqAlphabets(string s)
	{
		string res;
		for (int i = s.length() - 1; i >= 0; --i)
		{
			char c;
			if (s[i] == '#')
			{
				c = (s[i - 1] - '0') + (s[i - 2] - '0') * 10 - 10 + 'j';
				i -= 2;
			}
			else
				c = s[i] - '0' - 1 + 'a';
			res = c + res;
		}
		return res;
	}
};