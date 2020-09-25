#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
	string decodeString(string s)
	{
		stack<pair<int, string>> stk; //{count,previous str}
		string res;
		for (int i = 0, n = 0; i < (int)s.length(); ++i)
		{
			if (isalpha(s[i]))
				res.push_back(s[i]);
			else if (isdigit(s[i]))
			{
				n = 0;
				while (s[i] != '[')
					n = n * 10 + s[i++] - '0';
				stk.push({n, res});
				res.clear();
			}
			else
			{
				string data;
				for (int j = 0; j < stk.top().first; ++j)
					data += res;
				data = stk.top().second + data;
				res = data;
				stk.pop();
			}
		}
		return res;
	}
};