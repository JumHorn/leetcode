#include <string>
using namespace std;

/*
view string as a stack
*/

class Solution
{
public:
	bool isValid(string s)
	{
		int top = -1;
		for (auto c : s)
		{
			if (c == 'c' && top >= 1 && s[top] == 'b' && s[top - 1] == 'a')
				top -= 2;
			else
				s[++top] = c;
		}
		return top == -1;
	}
};