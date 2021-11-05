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
			for (j = i + 1; j < N && s[i] == s[j];)
				++j;
			int count = j - i;
			if (!stk.empty() && stk.top().first == s[i])
			{
				count += stk.top().second;
				stk.pop();
			}
			if (count % k != 0)
				stk.push({s[i], count % k});
		}
		string res;
		for (; !stk.empty(); stk.pop())
			res = string(stk.top().second, stk.top().first) + res;
		return res;
	}
};