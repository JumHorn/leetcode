#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
	string reverseParentheses(string s)
	{
		int index = 0;
		return recursive(s, index, 0);
	}

	string recursive(string& s, int& index, int count)
	{
		string res;
		while (index < (int)s.length() && s[index] != ')')
		{
			if (s[index] == '(')
			{
				++index;
				if (count % 2 == 0)
					res = res + recursive(s, index, count + 1);
				else
					res = recursive(s, index, count + 1) + res;
			}
			else
			{
				int i = index;
				while (i < (int)s.length() && s[i] != ')' && s[i] != '(')
					i++;
				if (count % 2 == 0)
					res = res + s.substr(index, i - index);
				else
				{
					string tmp = s.substr(index, i - index);
					reverse(tmp.begin(), tmp.end());
					res = tmp + res;
				}
				index = i;
			}
		}
		++index;
		return res;
	}
};
