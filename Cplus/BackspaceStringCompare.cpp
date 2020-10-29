#include <string>
using namespace std;

class Solution
{
public:
	bool backspaceCompare(string S, string T)
	{
		return backspace(S) == backspace(T);
	}

	string backspace(string &s)
	{
		int top = -1;
		for (auto c : s)
		{
			if (c != '#')
				s[++top] = c;
			else if (top != -1)
				--top;
		}
		return s.substr(0, top + 1);
	}
};