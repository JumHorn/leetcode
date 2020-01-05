#include <string>
using namespace std;

class Solution
{
public:
	string freqAlphabets(string s)
	{
		string res;
		char tmp;
		for (int i = s.length() - 1; i >= 0; i--)
		{
			if (s[i] == '#')
			{
				tmp = (s[i - 1] - '0') + (s[i - 2] - '0') * 10 - 10 + 'j';
				i -= 2;
			}
			else
				tmp = s[i] - '0' - 1 + 'a';
			res = tmp + res;
		}
		return res;
	}
};
