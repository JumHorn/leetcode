#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
	vector<string> removeInvalidParentheses(string s)
	{
		int invalid_open = 0, invalid_closed = 0;
		for (auto c : s)
		{
			if (c == '(')
				++invalid_open;
			else if (c == ')')
				invalid_open > 0 ? --invalid_open : ++invalid_closed;
		}

		unordered_set<string> res;
		string instance;
		dfs(s, 0, invalid_open, invalid_closed, 0, instance, res);
		return vector<string>(res.begin(), res.end());
	}

	void dfs(const string &s, int index, int open, int closed, int count, string &instance, unordered_set<string> &res)
	{
		if (open < 0 || closed < 0 || count < 0)
			return;
		if (index > (int)s.length())
		{
			if (open == 0 && closed == 0 && count == 0)
				res.insert(instance);
			return;
		}
		if (open == 0 && closed == 0)
		{
			if (isValid(s, index, count))
				res.insert(instance + s.substr(index));
			return;
		}
		if (s[index] == '(')
		{
			dfs(s, index + 1, open - 1, closed, count, instance, res);
			instance.push_back('(');
			dfs(s, index + 1, open, closed, count + 1, instance, res);
			instance.pop_back();
		}
		else if (s[index] == ')')
		{
			dfs(s, index + 1, open, closed - 1, count, instance, res);
			instance.push_back(')');
			dfs(s, index + 1, open, closed, count - 1, instance, res);
			instance.pop_back();
		}
		else
		{
			instance.push_back(s[index]);
			dfs(s, index + 1, open, closed, count, instance, res);
			instance.pop_back();
		}
	}

	bool isValid(const string &s, int index, int count)
	{
		for (int i = index; i < (int)s.length(); ++i)
		{
			if (s[i] == ')' && --count < 0)
				return false;
			if (s[i] == '(')
				++count;
		}
		return count == 0;
	}
};