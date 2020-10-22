#include <stack>
#include <string>
using namespace std;

class Solution
{
public:
	string removeDuplicates(string s, int k)
	{
		stack<pair<char, int>> stk; //{char,count}
		int N = s.length();
		for (int i = 0, j = 0; i < N; i = j)
		{
			j = i + 1;
			while (j < N && s[i] == s[j])
				++j;
			if (stk.empty() || stk.top().first != s[i])
			{
				if ((j - i) % k != 0)
					stk.push({s[i], (j - i) % k});
			}
			else
			{
				if ((j - i + stk.top().second) % k != 0)
					stk.top().second = (j - i + stk.top().second) % k;
				else
					stk.pop();
			}
		}
		string res;
		while (!stk.empty())
		{
			res = string(stk.top().second, stk.top().first) + res;
			stk.pop();
		}
		return res;
	}
};