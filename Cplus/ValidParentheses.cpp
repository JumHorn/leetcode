#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
	bool isValid(string s)
	{
		unordered_map<char, char> m = {{')', '('}, {'}', '{'}, {']', '['}};
		int i = -1;
		for (int j = 0; j < (int)s.length(); ++j)
		{
			if (s[j] == ')' || s[j] == '}' || s[j] == ']')
			{
				if (i == -1 || s[i] != m[s[j]])
					return false;
				--i;
			}
			else
				s[++i] = s[j];
		}
		return i == -1;
	}
};